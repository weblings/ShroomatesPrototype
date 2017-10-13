// Fill out your copyright notice in the Description page of Project Settings.

#include "Growtest.h"
#include "ShroommateProtoCharacter.h"
#include "Qualities.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)


// Sets default values
AGrowtest::AGrowtest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//set mesh of the growing area
	GrowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GrowMesh"));
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootMesh"));
	GrowMesh->SetupAttachment(RootComponent);

	//set hitbox
	Hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("hitbox"));
	//sethitboxsize
	Hitbox->SetWorldScale3D(FVector(1.f, 1.f, 1.f));
	Hitbox->bGenerateOverlapEvents = true;
	Hitbox->OnComponentBeginOverlap.AddDynamic(this, &AGrowtest::onPlayerEnter);
	Hitbox->SetupAttachment(RootComponent);
	

	
}

// Called when the game starts or when spawned
void AGrowtest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrowtest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGrowtest::onPlayerEnter(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//debug
	print(OtherActor->GetName());
	//need to change this to work with actual character
	//make sure its actually the player touching it
	if (OtherActor->GetName() == "Character") {
		FVector NewScale = OtherActor->GetActorScale();
		OtherActor->SetActorRelativeScale3D(NewScale + FVector(0.5f, 0.5f, 0.5f));
		AShroommateProtoCharacter* tempChar = Cast<AShroommateProtoCharacter>(OtherActor);
		UQualities* tempq = tempChar->FindComponentByClass<UQualities>();
		tempq->addToHumidity(0.01f);
		print(FString::SanitizeFloat(tempq->getHumidity()));
		//remove actor from scene
		Destroy();
	}
}

