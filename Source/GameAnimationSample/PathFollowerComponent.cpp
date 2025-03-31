// Fill out your copyright notice in the Description page of Project Settings.


#include "PathFollowerComponent.h"
#if WITH_EDITOR
#include "Engine/Selection.h"
#include "Editor.h"
#endif
#include "Components/TextRenderComponent.h"
#include "Engine/TextRenderActor.h"

// Sets default values for this component's properties
UPathFollowerComponent::UPathFollowerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

#if WITH_EDITOR
	// Broadcast whenever the editor selection changes (viewport
	// or world outliner)
	USelection::SelectionChangedEvent.AddUObject(this, &UPathFollowerComponent::ChangedSelection);
#endif
}


// Called when the game starts
void UPathFollowerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

#if WITH_EDITOR
void UPathFollowerComponent::ChangedSelection(UObject* NewSelection)
{
	TArray<UPathFollowerComponent*> SelectedPathComps;
	
	USelection* Selection = Cast<USelection>(NewSelection);
	if (Selection != nullptr)
	{
		Selection->GetSelectedObjects<UPathFollowerComponent>(SelectedPathComps);
	}
	
	// Search the selection for this actor
	for (UPathFollowerComponent* SelectedPathComp : SelectedPathComps)
	{
		// If our actor is in the selection and was not previously
		// selected, then this selection change marks the actor
		// being selected
		if (SelectedPathComp == this && !bSelectedInEditor)
		{
			// Respond to this actor being selected
			bSelectedInEditor = true;
			EditSphereDebug();
		}
	}

	// If our record shows our actor is selected, but IsSelected() is false,
	// this selection change marks the actor being deselected
	if (bSelectedInEditor && !IsSelected())
	{
		// Respond to this actor being deselected
		bSelectedInEditor = false;
		FlushPersistentDebugLines(GetWorld());
		for(ATextRenderActor* TextRenderActor : TextInfos)
		{
			if(TextRenderActor)
			{
				TextRenderActor->Destroy();
			}
		}
	}
}

void UPathFollowerComponent::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	EditSphereDebug();
}

void UPathFollowerComponent::EditSphereDebug()
{
	FlushPersistentDebugLines(GetWorld());
	for(ATextRenderActor* TextRenderActor : TextInfos)
	{
		if(TextRenderActor)
		{
			//This doesn't seem to be hit
			TextRenderActor->Destroy();
		}
	}
	
	for(int i = 0; i < PathPoints.Num(); i++)
	{
		FVector Location(PathPoints[i].X, PathPoints[i].Y, PathPoints[i].Z + 25.0f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.ObjectFlags |= RF_Transient;
		ATextRenderActor* Act = GetWorld()->SpawnActor<ATextRenderActor>(ATextRenderActor::StaticClass(), Location, Rotation, SpawnInfo);
		Act->GetTextRender()->SetText(FText::AsNumber(i));
		Act->GetTextRender()->SetWorldSize(54.0f);
		TextInfos.Add(Act);
		DrawDebugSphere(GetWorld(), PathPoints[i], 30.0f, 48, (i == 0 ? FColor::Orange : FColor::Red), true, -1.0f, 0, 1.0f);
	}
	if(PathPoints.Num() == 2)
	{
		DrawDebugLine(GetWorld(), PathPoints[0], PathPoints[1],FColor::Orange, true, -1, 0, 2.0f);
	}
	else
	{
		for(int i = 0; i < PathPoints.Num(); i++)
		{
			DrawDebugLine(GetWorld(), PathPoints[i], PathPoints[(i+1) % PathPoints.Num()], (i == 0 ? FColor::Orange : FColor::Red), true, -1, 0, 2.0f);
		}
	}
}
#endif

