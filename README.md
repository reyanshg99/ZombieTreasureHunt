# Zombie Treasure Hunt

A first-person C++17 survival game built with OpenGL 3.3 Core, GLFW, GLEW, GLM, and Assimp. Explore an expanded forest, fight endless zombie waves, collect supplies, and retrieve the Rubik's Cube from the temple after wave 3.

## Requirements

On macOS with Homebrew:

```bash
brew install cmake glfw glew glm assimp
```

The project targets macOS Apple Silicon with OpenGL 3.3 Core. Runtime models and textures are included in `assets/`.

## Build, verify, and run

From the project root:

```bash
cmake -S . -B build
cmake --build build -j2
ctest --test-dir build --output-on-failure
./build/ZombieTreasureHunt
```

Use `./build/ZombieTreasureHunt --autostart` to bypass the title screen. `--self-test` runs gameplay/state checks without opening a window; `--asset-test` checks the supplied models and textures.

## Controls

- **Enter** — start / continue
- **W / A / S / D** — move
- **Mouse** — look and aim
- **Left Shift** — sprint
- **Space** — jump
- **Left mouse button** — fire
- **1 / 2** — pistol / shotgun
- **R** — reload
- **F** — melee
- **L** — flashlight
- **E** — collect nearby supplies or claim the unlocked treasure
- **I** — inventory
- **Escape** — pause and release the cursor; resume from the pause menu
- **Up / Down / Enter** — menu navigation
- **- / =** — adjust mouse sensitivity on title/settings screens

The mouse is captured while playing. Escape pauses and releases it.

## Gameplay

Wave 1 starts with 10 zombies; each later wave adds five, with health and speed scaling by wave. Zombies chase and attack at close range, react to hits, and stay visible after death. Camera-centered shots damage enemies; headshots deal bonus damage. Pistol and shotgun use magazines and reserves. Clear wave 3 to unlock the cube; claim it with **E** during a safe intermission to win. The HUD displays player health, stamina, ammo, wave and kill counts, objectives, hit feedback, and a full-world minimap.

## Project layout

- `src/Game.cpp` — game state, world, input, combat, HUD, and rendering
- `src/Model.cpp` — Assimp model/texture import and skeletal animation
- `src/WaveManager.cpp` — endless wave progression and difficulty scaling
- `shaders/` — runtime GLSL 3.3 shaders
- `assets/` — runtime and source art; see [ASSET_INVENTORY.md](ASSET_INVENTORY.md)
- `THIRD_PARTY_ASSETS.md` — credits and license notes
- `third_party/stb_image.h` — bundled image decoder

## Rendering and limitations

The forest uses Kenney low-poly tree, rock, bush, and grass models, a tiled ground texture, textured temple masonry, directional lighting, fog, and a flashlight. Zombies use the supplied textured static mesh with a shader-driven standing pose and gait; the source rig is retained and asset-checked. The shotgun uses its supplied animation clips; the pistol and hands presentation are procedural. The renderer does not currently implement dynamic shadow maps or screen-space ambient occlusion. No audio backend or sound assets are included.
