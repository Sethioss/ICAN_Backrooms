// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthLostSignature, int32, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEANIMATIONSAMPLE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UPROPERTY(BlueprintAssignable)
	FOnHealthLostSignature OnHealthLost;

	UPROPERTY(BlueprintAssignable)
	FOnDeathSignature OnDeath;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int MaxHealth = 3;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int CurrentHealth;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsDead;
	
	UFUNCTION(BlueprintCallable)
	void RemoveHealth(int Damage);

	UFUNCTION(BlueprintCallable)
	void Die();
};
