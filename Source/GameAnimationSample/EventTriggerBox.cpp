// Fill out your copyright notice in the Description page of Project Settings.


#include "EventTriggerBox.h"
#include "Components/BoxComponent.h"

// Sets default values
AEventTriggerBox::AEventTriggerBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	TriggerBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBoxComponent->SetupAttachment(RootComponent);

}

void AEventTriggerBox::PlayEventFromID(int index)
{
}

void AEventTriggerBox::StartEventList()
{
}

void AEventTriggerBox::PlayNextEvents()
{
}

