// Fill out your copyright notice in the Description page of Project Settings.

#include "MyShip.h"
#include "MyShipActor.h"

AMyShipActor::AMyShipActor()
{
	// ����ÿ֡Tick���ã�Ϊ�˽�ʡЧ�ʣ����������Ĭ�Ϲرյ�
	PrimaryActorTick.bCanEverTick = true;


	// ��ʼ���ڲ�����
	WaveStrength = 1.8f;

	WaveFactor = FVector2D::ZeroVector;

	WaveOffset.X = FMath::FRandRange(0, WaveStrength * 10);
	WaveOffset.Y = FMath::FRandRange(0, WaveStrength * 10);
}

void AMyShipActor::PostInitProperties()
{
	Super::PostInitProperties();

	WaveOffset.X = FMath::FRandRange(0, WaveStrength * 10);
	WaveOffset.Y = FMath::FRandRange(0, WaveStrength * 10);
}

#if WITH_EDITOR
void AMyShipActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	WaveOffset.X = FMath::FRandRange(0, WaveStrength * 10);
	WaveOffset.Y = FMath::FRandRange(0, WaveStrength * 10);
}
#endif // WITH_EDITOR

void AMyShipActor::BeginPlay()
{
	Super::BeginPlay();

	// ��Ҫҡ�ڣ����Ա����ǿ��ƶ���
	SetMobility(EComponentMobility::Movable);

	UStaticMesh* MyMesh = Cast<UStaticMesh>(
		StaticLoadObject(UStaticMesh::StaticClass(),
		NULL,
		TEXT("/Game/StaticMeshes/SM_Ship.SM_Ship"))
		);
	if (MyMesh != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Load Static Mesh OK"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Load Static Mesh FAILED"));
	}

}

void AMyShipActor::Tick(float DeltaTime)
{
	// ���û����Tick
	Super::Tick(DeltaTime);

	const FTimerManager& timeMgr = GetWorld()->GetTimerManager();

	float delta = DeltaTime*WaveStrength;

	WaveFactor.X += delta*0.73f;
	WaveFactor.Y += delta*1.22f;

	FRotator rot(0, 0, 0);
	rot.Pitch = FMath::Sin(WaveOffset.X + WaveFactor.X)*WaveStrength*0.75f;
	rot.Roll = FMath::Sin(WaveOffset.Y + WaveFactor.Y)*WaveStrength*1.5f;

	bool ok = SetActorRotation(rot);
}