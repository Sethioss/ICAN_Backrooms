// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScriptedEvent.h"
#include "EventTriggerBox.generated.h"

class UBoxComponent;
class UScriptedEvent;

UCLASS()
class GAMEANIMATIONSAMPLE_API AEventTriggerBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventTriggerBox();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UScriptedEvent>> Events;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int CurrentEventID;

protected:
	UBoxComponent* TriggerBoxComponent = nullptr;

	UFUNCTION(BlueprintCallable)
	void PlayEventFromID(int index);
	
	UFUNCTION(BlueprintCallable)
	void StartEventList();

	UFUNCTION(BlueprintCallable)
	void PlayNextEvents();
};
