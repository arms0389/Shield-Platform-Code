// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Shield.generated.h"

UCLASS()
class COOPMECHANICS_API AShield : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShield();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	class UBoxComponent* ShieldCollider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
	class UStaticMeshComponent* ShieldMesh;

	void ShieldEnable(bool e);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
