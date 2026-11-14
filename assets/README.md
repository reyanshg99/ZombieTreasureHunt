# Runtime assets

The game loads models and textures relative to the project root (or executable location). Keep these paths intact when copying the built application. Assimp imports GLB/OBJ/FBX models and `stb_image` decodes image textures.

- `models/zombies/SZombie/` — supplied static zombie mesh used at runtime with its albedo; shader-driven posing animates its T-pose into a standing gait
- `models/zombie/` — supplied skeletal source FBX and maps retained for reference and asset validation
- `models/weapons/` — animated Saiga shotgun and embedded textures
- `models/hands/` — rigged first-person hands asset
- `models/kenney/` — CC0 forest tree and prop models used throughout the world
- `models/ground_plane.obj` and `textures/forest_ground_1k.jpg` — tiled forest floor
- `models/textured_cube.obj` and `textures/temple_stone_1k.jpg` — UV-mapped temple and ruin masonry
- `sounds/` — reserved for future audio content; no sound files or audio backend are currently included

See `../ASSET_INVENTORY.md` for usage details and `../THIRD_PARTY_ASSETS.md` for attribution and license notes.
