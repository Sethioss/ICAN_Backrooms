// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PathFollowerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEANIMATIONSAMPLE_API UPathFollowerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPathFollowerComponent();

	UPROPERTY(Transient)
	TArray<class ATextRenderActor*> TextInfos;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	void ChangedSelection(UObject* NewSelection);
	bool bSelectedInEditor;

	void EditSphereDebug();
#endif
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	TArray<FVector> PathPoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	int CurrentWayPointID;
};
