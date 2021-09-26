// Fill out your copyright notice in the Description page of Project Settings.


#include "Shield.h"
#include "Components/BoxComponent.h"

// Sets default values
AShield::AShield()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShieldCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("ShieldComp"));
	ShieldCollider->InitBoxExtent(FVector(40.0f, 40.0f, 2.5f));
	ShieldCollider->SetEnableGravity(false);
	ShieldCollider->SetNotifyRigidBodyCollision(true);
	ShieldCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	ShieldCollider->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	SetRootComponent(ShieldCollider);

	ShieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShieldMesh"));
	ShieldMesh->SetSimulatePhysics(false);
	ShieldMesh->SetCollisionProfileName("NoCollision");
	ShieldMesh->SetRelativeScale3D(FVector(0.02f));
	ShieldMesh->SetupAttachment(ShieldCollider);
	ShieldMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 2.0f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>FindShieldMesh(TEXT("/Game/Geometry/Meshes/TemplateFloor"));
	if (FindShieldMesh.Succeeded())
	{
		ShieldMesh->SetStaticMesh(FindShieldMesh.Object);
	}

	ShieldEnable(false);
}

void AShield::ShieldEnable(bool e)
{
	SetActorHiddenInGame(!e);
	SetActorEnableCollision(e);
	SetActorTickEnabled(e);
	ShieldMesh->SetHiddenInGame(!e);
	//ShieldCollider->SetCollisionEnabled(e? (ECollisionEnabled::QueryAndPhysics):(ECollisionEnabled::NoCollision));
}

// Called when the game starts or when spawned
void AShield::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShield::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
//void AShield::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

