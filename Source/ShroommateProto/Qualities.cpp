// Fill out your copyright notice in the Description page of Project Settings.

#include "Qualities.h"


// Sets default values for this component's properties
UQualities::UQualities()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	light = 0.5f; //Having them all start at 0.5f for now
	temperature = 0.5f;
	humidity = 0.5f;
}


// Called when the game starts
void UQualities::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQualities::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
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

float UQualities::addToTemp(float change) {
	if (temperature + change >= 1) {
		temperature = 1;
	}else if (temperature + change <= 0) {
		temperature = 0;
	}else {
		temperature += change;
	}
	return temperature;
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

float UQualities::setTemp(float newTemp) {
	if (newTemp >= 1) {
		temperature = 1;
	}else if (newTemp <= 0) {
		temperature = 0;
	}else {
		temperature = newTemp;
	}
	return temperature;
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

float UQualities::getTemp() {
	return temperature;
}

float UQualities::getHumidity() {
	return humidity;
}

