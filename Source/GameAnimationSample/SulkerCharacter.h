// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Engine/TextRenderActor.h"
#include "SulkerCharacter.generated.h"

UCLASS()
class GAMEANIMATIONSAMPLE_API ASulkerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASulkerCharacter();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UBehaviorTreeComponent> BehaviorTree;

	UPROPERTY(Transient)
	TArray<ATextRenderActor*> TextInfos;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	
	void ChangedSelection(UObject* NewSelection);
	bool bSelectedInEditor;

	void EditSphereDebug();
#endif

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	TArray<FVector> PathPoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	int CurrentWayPointID;

};
