// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SulkerAIController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEANIMATIONSAMPLE_API ASulkerAIController : public AAIController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyAI|Detection")
	float PlayerDetectionRadius = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyAI|Detection")
	float PlayerLoseSightRadius = 500.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyAI|PatrolingBehaviour")
	float PostReachedPathPointWaitingInSeconds = 2.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnemyAI|AttackBehaviour")
	float PostHitWaitingInSeconds = 2.5f;
};
