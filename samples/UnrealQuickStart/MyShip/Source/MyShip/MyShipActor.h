// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "ShipWeapon.h"
#include "MyShipActor.generated.h"

UCLASS()
class MYSHIP_API AMyShipActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	// ���캯��
	AMyShipActor();

	// ��Ϸ��ʼʱ���ã��൱��Unity��Start()
	virtual void BeginPlay() override;
	
	// ÿ֡���ã��൱Unity��Update()
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category="MyShipGame")
    float WaveStrength;

	UPROPERTY(VisibleAnywhere, Category = "MyShipGame")
	FVector2D WaveOffset;

	/** �������� */
	UPROPERTY(EditAnywhere, Category = "MyShipGame")
	TSubclassOf<AShipWeapon> WeaponType;


	virtual void PostInitProperties() override;
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR

private:
	FVector2D WaveFactor;
};
