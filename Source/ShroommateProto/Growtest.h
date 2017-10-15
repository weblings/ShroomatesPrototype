// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Growtest.generated.h"

UCLASS()
class SHROOMMATEPROTO_API AGrowtest : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* GrowMesh;


	//set pickup hitbox
	UPROPERTY(EditAnywhere)
	class UShapeComponent* Hitbox;

	UPROPERTY(Category = Type, EditAnywhere)
	TArray<FString> Type = { TEXT("Hunger"), TEXT("Humidity"), TEXT("Light") };

	APlayerController* Controller;
	
public:	
	// Sets default values for this actor's properties

	AGrowtest();

	
	//set mesh component
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void onPlayerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult  );

	
	
};
