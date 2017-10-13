// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	float temperature;
	UPROPERTY(Category = Qualities, EditAnywhere)
	float humidity;

public:	
	// Sets default values for this component's properties
	UQualities();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	//My functions---------------------------------------------------------------
	
	//Adds to them (can use negative numbers for subtracting)
	float addToLight(float change);
	float addToTemp(float change);
	float addToHumidity(float change);
	
	//setters
	float setLight(float newLight);
	float setTemp(float newTemp);
	float setHumidity(float newHumidity);

	//getters
	float getLight();
	float getTemp();
	float getHumidity();



		
	
};
