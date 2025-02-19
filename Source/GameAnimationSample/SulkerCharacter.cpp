// Fill out your copyright notice in the Description page of Project Settings.


#include "SulkerCharacter.h"
#include "Engine/Selection.h"
#include "Editor.h"
#include "Components/TextRenderComponent.h"
#include "Util/ColorConstants.h"

// Sets default values
ASulkerCharacter::ASulkerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BehaviorTree = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree"));

#if WITH_EDITOR
	// Broadcast whenever the editor selection changes (viewport
	// or world outliner)
	USelection::SelectionChangedEvent.AddUObject(this, &ASulkerCharacter::ChangedSelection);
#endif

}

// Called when the game starts or when spawned
void ASulkerCharacter::BeginPlay()
{
	Super::BeginPlay();

	FlushPersistentDebugLines(GetWorld());
}

void ASulkerCharacter::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	EditSphereDebug();
}

#if WITH_EDITOR
void ASulkerCharacter::ChangedSelection(UObject* NewSelection)
{
	TArray<ASulkerCharacter*> SelectedSulkers;
	
	USelection* Selection = Cast<USelection>(NewSelection);
	if (Selection != nullptr)
	{
		Selection->GetSelectedObjects<ASulkerCharacter>(SelectedSulkers);
	}
	
	// Search the selection for this actor
	for (ASulkerCharacter* SelectedSulker : SelectedSulkers)
	{
		// If our actor is in the selection and was not previously
		// selected, then this selection change marks the actor
		// being selected
		if (SelectedSulker == this && !bSelectedInEditor)
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
#if 1
		for(ATextRenderActor* TextRenderActor : TextInfos)
		{
			if(TextRenderActor)
			{
				TextRenderActor->Destroy();
			}
		}
#endif
	}
}

void ASulkerCharacter::EditSphereDebug()
{
	FlushPersistentDebugLines(GetWorld());
#if 1
	for(ATextRenderActor* TextRenderActor : TextInfos)
	{
		if(TextRenderActor)
		{
			TextRenderActor->Destroy();
		}
	}
#endif
	
	for(int i = 0; i < PathPoints.Num(); i++)
	{
#if 1
		FVector Location(PathPoints[i].X, PathPoints[i].Y, PathPoints[i].Z + 25.0f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.ObjectFlags |= RF_Transient;
		ATextRenderActor* Act = GetWorld()->SpawnActor<ATextRenderActor>(ATextRenderActor::StaticClass(), Location, Rotation, SpawnInfo);
		Act->GetTextRender()->SetText(FText::AsNumber(i));
		Act->GetTextRender()->SetWorldSize(54.0f);
		TextInfos.Add(Act);
#endif
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

// Called every frame
void ASulkerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASulkerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

