# InfinitySpire (UE5.6 Prototype)
Fully playable Unreal Engine 5.6 prototype for a voxel‑based survival • city builder • factory • RPG — with multiplayer, space/time travel, and multiverse ambitions.

## What’s Included
- **InfinitySpire.uproject** — ready-to-open UE5.6 project file
- **Config/** — default maps, input bindings (WASD + controller), and project metadata
- **GameDesignDoc.md** — full GDD v1.0 (vision, pillars, tech tree, roadmap)
- **Source/InfinitySpire/** — gameplay module with:
  - `VoxelBlock` — block enum/struct
  - `InventoryComponent` — items/stacking, simple add/remove (replication-ready)
  - `SurvivalComponent` — health/hunger/stamina (replicated)
  - `PlayerCharacter` — replicated survival avatar with FPS/TPS camera toggle and tuned movement
  - `MonsterAIController` — basic server‑auth chase/attack placeholder
  - `VoxelWorld` — instanced static-mesh ground grid for instant playable sandbox
  - `InfinitySpireGameMode` — auto-spawns player + voxel world so PIE works immediately
  - Build/Target files for Editor + Game

## Quick Start
1. Install **Unreal Engine 5.6**.
2. Open `InfinitySpire.uproject` (right-click → *Generate Visual Studio project files* if needed).
3. Build from Visual Studio / Rider or let the Unreal Editor compile modules on launch.
4. Press **Play** — you spawn as the custom `PlayerCharacter` on an auto-generated voxel ground plane.
5. Tap **V** to toggle between first-person and third-person cameras.

## Multiplayer Notes
- Components and characters set `bReplicates = true` where needed.
- `SurvivalComponent` variables replicate via `GetLifetimeReplicatedProps`.
- Add replication to inventory or block placement as you implement gameplay logic.
- For local tests: **Play** → **Number of Players: 2** → **Run Dedicated Server: true/false**.

## GitHub Tips
Add a `.gitignore` for Unreal to exclude `Binaries/`, `Intermediate/`, `DerivedDataCache/`, `Saved/`.
Use **Git LFS** for large assets (textures, audio, models).

## Next Implementation Targets
- Chunk meshing (ProceduralMeshComponent or Runtime Mesh Component)
- Block placement traces + server RPCs
- Simple crafting UI (UMG) reading JSON recipes
- AI perception for monsters (UPawnSensing / AISense_Sight)
- Dedicated server build target & CI workflow

