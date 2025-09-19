# InfinitySpire — Game Design Document (v1.0)

**Genres:** City Builder • Survival • Factory • RPG • Open World • Voxel • Sci‑Fi • FPS/TPS • Multiplayer  
**Scope:** Planet → Space → Time → Multiverse (dimensions & parallel universes)

## 1) Core Vision
A limitless voxel-based sci‑fi sandbox where players survive, build houses/cities, automate factories, fight monsters, research technology, pilot starships, and eventually master **time** and **dimensions**. Switch between **first** and **third person** and play **solo or co‑op** on client-server multiplayer.

## 2) Pillars
1. Survival & Exploration (biomes, hazards, day/night, weather, creatures)
2. Building & City (blocks + prefabs; house designer; NPC settlers & needs)
3. Factory & Automation (miners, refiners, assemblers, conveyors, power & logistics)
4. Combat & RPG (FPS/TPS, loot, skills, implants, bosses, quests)
5. Space Travel (ships, warp/wormholes, orbital/planetary colonies)
6. Time/Dimensional Travel (past/future variants; mirror universes; rifts)
7. Procedural Living Worlds (ecosystems, factions, emergent events)
8. Multiplayer & Mods (co‑op servers; moddable data & systems)

## 3) Gameplay Loop
**Early:** land → gather → craft → shelter → fight → survive  
**Mid:** machines → power → automation → settlers → city planning  
**Late:** starships → colonies → wars/diplomacy → anomalies  
**End:** time machines → dimensional gates → megastructures (Dyson sphere) → ascension tools

## 4) Progression — Tech Tree (T0→T7)
- **T0 Primitive:** stone tools; campfire; basic shelter
- **T1 Early Industry:** furnace, iron tools; wood/coal energy; simple farms
- **T2 Industrial:** steam; conveyors/pumps; settlers; chemistry; early guns
- **T3 Modern:** oil/electricity; assembly lines; trains/trucks; robotics
- **T4 Futuristic/Space:** nuclear/solar; drones/AI logistics; aircraft/starships; exosuits
- **T5 Interstellar:** antimatter; nanotech; wormholes; orbital stations & colonies
- **T6 Temporal/Dimensional:** zero‑point; time machines; interdimensional gates; chrono‑weapons
- **T7 Ascension:** reality fabricators; universe‑scale megastructures; godlike sandbox roles

## 5) World & Biomes
Voxel planets with forests, deserts, tundra, oceans, volcanic/frozen/alien biomes; ruins & dungeons; anomalies. Universes: Prime, Shattered Realms (warped physics), Mirror Universes (alt history), Time Variants (past/future), Cosmic Core hub.

## 6) Creatures & Factions
Wildlife (neutral/hostile), monsters (mutants & horrors), bosses, alien civilizations with diplomacy/trade/war, cosmic entities tied to time/dimensions.

## 7) Building, City & Factory
- **Build:** blocks + prefab modules; interior designer; snap & grid; décor
- **Factory:** miners/refiners/assemblers; conveyors/pipes; robotics; power (fuel→nuclear→exotic); logistics networks
- **City:** settlers, jobs, housing, services, economy & policies
- **Research:** labs unlock tiers; narrative quests reveal time/dimensional science

## 8) RPG & Story
Main arc: survivor → explorer → empire builder → temporal/dimensional architect.  
Side quests, contracts, ruins, anomalies, boss hunts, faction arcs.  
Skills: Engineering, Survival, Combat, Temporal/Dimensional Mastery.

## 9) Multiplayer
Unreal client‑server replication. Co‑op survival first (2–8 players).  
Replicate player state (inventory/health), block placement, machines & NPCs (server authoritative).  
Dedicated server later for persistent worlds.

## 10) Phases (Dev Roadmap)
1. **Core Survival Voxel**: chunks, player, inventory, crafting, monsters
2. **Factory & City**: machines/power/logistics; settlers & needs
3. **Space**: ships; interplanetary travel; orbital stations
4. **RPG & Factions**: quests, diplomacy/war, starship combat
5. **Time/Dimensions**: time variants; dimensional rifts; meta‑progress
6. **Endgame**: megastructures; ascension roles; godlike sandbox tools

## 11) Art & UI
Stylized voxels + high‑res PBR; minimalist holo‑UI; accessibility and clean typography; diegetic HUD where possible.

## 12) Risks
Scope creep, performance (voxels + AI + factories), balance complexity.  
Mitigations: phased delivery, modular systems, data‑driven content, automated tests, profiling.

## 13) MVP (First Milestone)
- Chunked voxel terrain (placeholder meshes)
- Player controller (FPS/TPS toggle), inventory/hunger/health
- Block place/remove, simple crafting (Workbench, Furnace)
- One monster with chase/attack AI
- Replication for player stats and block events

