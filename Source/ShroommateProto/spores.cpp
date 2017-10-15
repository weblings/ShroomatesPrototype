// Fill out your copyright notice in the Description page of Project Settings.

#include "spores.h"


// Sets default values for this component's properties
Uspores::Uspores()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	EnableInput(this);

	// ...
}


// Called when the game starts
void Uspores::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}




// Called every frame
void Uspores::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsInputKeyDown(EKeys::F)) {

	}
	// ...
}

