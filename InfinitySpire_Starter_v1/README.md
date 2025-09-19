# InfinitySpire (Starter)
Unreal Engine 5 prototype scaffolding for a voxel‑based survival • city builder • factory • RPG — with multiplayer, space/time travel, and multiverse ambitions.

## What’s Included
- **GameDesignDoc.md** — full GDD v1.0 (vision, pillars, tech tree, roadmap)
- **C++ scaffolding** for core gameplay modules:
  - `VoxelBlock` — block enum/struct
  - `InventoryComponent` — items/stacking, simple add/remove (replication-ready)
  - `SurvivalComponent` — health/hunger/stamina (replicated)
  - `PlayerCharacter` — inventory + camera toggle (FPS/TPS), input bindings
  - `MonsterAIController` — basic server‑auth chase/attack placeholder
  - `VoxelWorld` — placeholder Actor for chunk/mesh generation hook points

> Drop the contents of `Source/InfinitySpire` into your UE5 C++ project (same module name) and compile.

## Quick Start
1. Create a **UE5 C++ → First Person** project named **InfinitySpire**.
2. Close the editor. Copy `Source/InfinitySpire/*` from this package into your project’s `Source/InfinitySpire/` folder.
3. Reopen in UE; let it compile. If needed, regenerate project files from the `.uproject` menu.
4. In Project Settings → Input, add an Action Mapping:
   - **ToggleView** → key: `V`
5. Place a `VoxelWorld` Actor in a test map (it’s a placeholder; you’ll wire chunk gen later).

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

