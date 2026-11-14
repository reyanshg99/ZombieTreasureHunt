# Asset inventory

This inventory distinguishes files used by the game from retained source/reference art. Paths are relative to the project root.

## Runtime models

| Path | Purpose | Runtime use |
|---|---|---|
| `assets/models/zombies/SZombie/SZombie_Variant_1/SM_SZombie_Variant_1.fbx` | Supplied zombie character mesh | Rendered for living zombies; vertex shader supplies an upright pose and gait |
| `assets/models/weapons/saiga_animated.glb` | First-person shotgun | Rendered with idle, walk, fire, and reload animation clips |
| `assets/models/hands/first_person_hands_rigged.glb` | First-person hands | Included and loaded for the weapon presentation |
| `assets/models/kenney/tree_detailed.glb`, `tree_fat.glb`, `tree_pineTallA_detailed.glb`, `tree_pineRoundA.glb` | Broadleaf and pine variety | Rendered as forest trees |
| `assets/models/kenney/rock_largeA.glb`, `rock_largeB.glb`, `rock_largeD.glb` | Rock variants | Distributed through the forest |
| `assets/models/kenney/plant_bushDetailed.glb`, `grass_large.glb` | Undergrowth | Available for environmental detail rendering |
| `assets/models/ground_plane.obj` | UV-mapped ground plane | Rendered with the forest floor albedo |
| `assets/models/textured_cube.obj` | UV-mapped cube mesh | Scaled into temple and ruin masonry pieces |

## Runtime textures and shaders

| Path | Purpose |
|---|---|
| `assets/textures/forest_ground_1k.jpg` | Tiled forest terrain albedo |
| `assets/textures/temple_stone_1k.jpg` | Temple and ruin masonry albedo |
| `assets/models/zombie/T_SZombie_Variant_1_A_Albedo.png` | Zombie character albedo assigned to the runtime mesh |
| `shaders/vertex.glsl`, `shaders/fragment.glsl` | OpenGL 3.3 vertex posing/skinning and lit/fogged fragment rendering |

The Rubik's Cube and pistol are procedurally generated in C++.

## Source and reference assets

`assets/models/zombie/` retains the provided skeletal FBX, textures, and source variants. The runtime uses the static mesh because its skeleton's imported bind matrices collapse the model in this renderer. `assets/models/kenney/` contains the Kenney Nature Kit source collection, of which a subset is used at runtime. Original high-resolution texture packs and source artwork are retained alongside optimized 1K runtime albedos. `assets/models/weapons/` and `assets/models/hands/` retain their provided source/animation files.

## Audio

The project bundle contained no sound files. There is currently no audio playback backend; `assets/sounds/README.md` records this limitation.

## Credits and redistribution

See [THIRD_PARTY_ASSETS.md](THIRD_PARTY_ASSETS.md) for asset creators, license information, and attribution. The supplied zombie asset archive had no license information, so its redistribution rights remain unverified.
