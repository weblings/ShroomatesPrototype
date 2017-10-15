// Fill out your copyright notice in the Description page of Project Settings.

#include "Qualities.h"
#include "ShroommateProtoCharacter.h"


// Sets default values for this component's properties
UQualities::UQualities()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	light = 0.61f; //Having them all start at 0.5f for now
	hunger = 0.61f;
	humidity = 0.61f;
}


// Called when the game starts
void UQualities::BeginPlay()
{
	Super::BeginPlay();
	player = GetOwner();
	// ...
	
}


// Called every frame
void UQualities::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	//Player Scaling
	FVector NewScale = player->GetActorScale();
	float growthAmount = growthRate();
	if(NewScale.X + growthAmount > .1) player->SetActorRelativeScale3D(NewScale + FVector(growthAmount, growthAmount, growthAmount));
	
	//Decay qualities
	addToLight(-decayRate);
	addToHunger(-decayRate);
	addToHumidity(-decayRate);
}

// My functions -------------------------------------------------------

//Adds to them (can use negative numbers for subtracting)
float UQualities::addToLight(float change) {
	if (light + change >= 1) {
		light = 1;
	}else if (light + change <= 0) {
		light = 0;
	}else {
		light += change;
	}
	return light;
}

float UQualities::addToHunger(float change) {
	if (hunger + change >= 1) {
		hunger = 1;
	}else if (hunger + change <= 0) {
		hunger = 0;
	}else {
		hunger += change;
	}
	return hunger;
}

float UQualities::addToHumidity(float change) {
	if (humidity + change >= 1) {
		humidity = 1;
	}else if (humidity + change <= 0) {
		humidity = 0;
	}else {
		humidity += change;
	}
	return humidity;
}

//setters
float UQualities::setLight(float newLight) {
	if (newLight >= 1) {
		light = 1;
	}else if (newLight <= 0) {
		light = 0;
	}else {
		light = newLight;
	}
	return light;
}

float UQualities::setHunger(float newTemp) {
	if (newTemp >= 1) {
		hunger = 1;
	}else if (newTemp <= 0) {
		hunger = 0;
	}else {
		hunger = newTemp;
	}
	return hunger;
}

float UQualities::setHumidity(float newHumidity) {
	if (newHumidity >= 1) {
		humidity = 1;
	}else if (newHumidity <= 0) {
		humidity = 0;
	}else {
		humidity = newHumidity;
	}
	return humidity;
}

//getters
float UQualities::getLight() {
	return light;
}

float UQualities::getHunger() {
	return hunger;
}

float UQualities::getHumidity() {
	return humidity;
}

//AG 10/14/17: Helper function for growthRate()
int UQualities::qualityState(float q) {
	int state = 0;
	if (q >= 0.5 + threshold) state = 1;
	else if (q < 0.5 - threshold) state = -1;
	return state;
}

//AG 10/14/17: Adding function that determines if player should grow or shrink and by how much
float UQualities::growthRate() {

	
	//Check qualities' relation to thresholds
	int humState = qualityState(humidity);
	int hunState = qualityState(hunger);
	int ligState = qualityState(light);

	int state = humState + hunState + ligState;

	if (state == -3) return -.0001; //-y=(.02)^1.1
	else if (state == -2) return -.00004; //-y=(.02)
	else if (state == -1) return -.00001; //-y=(.02)^(1/1.1)
	else if (state == 0) return 0;
	else if (state == 1) return .00001; //y=(.02)^(1/1.1)
	else if (state == 2) return .00004; //y=(.02)
	else return .0001; //if (state == 3)  //y=(.02)^1.1

}
