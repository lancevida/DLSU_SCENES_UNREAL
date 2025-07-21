// AverageFPSActor.cpp
#include "AverageFPSActor.h"
#include "Engine/Engine.h"

AAverageFPSActor::AAverageFPSActor()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AAverageFPSActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    DeltaTimes.Add(DeltaTime);
    if (DeltaTimes.Num() > SampleSize)
    {
        DeltaTimes.RemoveAt(0);
    }

    float AvgFPS = CalculateAverageFPS();
    GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, FString::Printf(TEXT("Avg FPS: %.2f"), AvgFPS));
}

float AAverageFPSActor::CalculateAverageFPS() const
{
    float Total = 0.f;
    for (float Time : DeltaTimes)
    {
        Total += Time;
    }

    float AverageDelta = Total / DeltaTimes.Num();
    return (AverageDelta > 0) ? 1.f / AverageDelta : 0.f;
}