// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementConstraintChangeBox.h"

// Sets default values
AMovementConstraintChangeBox::AMovementConstraintChangeBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	RootComponent = Trigger;

}

// Called when the game starts or when spawned
void AMovementConstraintChangeBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovementConstraintChangeBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

