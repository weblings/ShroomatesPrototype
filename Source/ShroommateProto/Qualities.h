// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "Qualities.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHROOMMATEPROTO_API UQualities : public UActorComponent
{
	GENERATED_BODY()

	//vars (Going to have these be 0-1 for now)
	
	UPROPERTY(Category = Qualities, EditAnywhere)
	float light;
	UPROPERTY(Category = Qualities, EditAnywhere)
	float hunger;
	UPROPERTY(Category = Qualities, EditAnywhere)
	float humidity;
	
	UPROPERTY(EditAnywhere)
	float threshold = .1; //AG 10/14/17: Adding threshold for growthRate()
	UPROPERTY(EditAnywhere)
	float decayRate = .00001; //AG 10/14/17: Decays qualities over time

	UPROPERTY(Category = Qualities, EditAnywhere)
	float curSize; //AG 10/14/17: player's current size
	UPROPERTY(Category = Qualities, EditAnywhere)
	float largestSize = 0; //AG 10/14/17: player's largest size ever


public:	
	// Sets default values for this component's properties
	UQualities();



protected:

	//AG 10/14/17: Protected vars	
	AActor * player; //will be used to access actor attached to this script

	// Called when the game starts
	virtual void BeginPlay() override;
	
	//AG 10/14/17: Helper function for growthRate()
	int qualityState(float q);
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	//My functions---------------------------------------------------------------
	
	//Adds to them (can use negative numbers for subtracting)
	float addToLight(float change);
	float addToHunger(float change);
	float addToHumidity(float change);
	
	//setters
	float setLight(float newLight);
	float setHunger(float newTemp);
	float setHumidity(float newHumidity);

	//getters
	float getLight();
	float getHunger();
	float getHumidity();

	//AG 10/14/17: Adding function that determines if player should grow or shrink and by how much
	float growthRate();

		
	
};
