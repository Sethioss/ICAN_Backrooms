// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "MovementConstraintChangeBox.generated.h"

UENUM(BlueprintType, Blueprintable)
enum EGait
{
	Walking     UMETA(DisplayName = "Walking"),
	Strafing      UMETA(DisplayName = "Strafing"),
	Sprinting   UMETA(DisplayName = "Sprinting"),
	Aiming   UMETA(DisplayName = "Aiming"),
	NONE	UMETA(DisplayName = "None")
};

UCLASS()
class GAMEANIMATIONSAMPLE_API AMovementConstraintChangeBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovementConstraintChangeBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> Trigger;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Enter")
	TArray<TEnumAsByte<EGait>> GaitsToMakeAvailableOnEnter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Enter")
	TEnumAsByte<EGait> GaitToForceOnEnter;

};
