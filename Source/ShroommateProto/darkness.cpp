// Fill out your copyright notice in the Description page of Project Settings.

#include "darkness.h"


// Sets default values
Adarkness::Adarkness()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Adarkness::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Adarkness::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (inShade) {

	}

}

void Adarkness::onPlayerEnterShadow(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	inShade = true;
}

void Adarkness::onPlayerExitShadow(AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	inShade = false;
}

