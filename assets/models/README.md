# Models

- `zombies/SZombie/SZombie_Variant_1/SM_SZombie_Variant_1.fbx` — static textured zombie mesh used at runtime. A vertex shader rotates its T-pose arms and animates its leg gait so the character stands upright.
- `zombie/SK_SZombie_Variant_1.fbx` — supplied skeletal zombie source retained and checked by asset tests; its bind matrices do not produce a stable runtime pose in the current importer.
- `weapons/saiga_animated.glb` — animated first-person shotgun with idle, walk, fire, and reload clips.
- `hands/first_person_hands_rigged.glb` — supplied rigged hands asset.
- `kenney/` — low-poly broadleaf/pine trees, rocks, bushes, and grass; source files are CC0.
- `ground_plane.obj` and `textured_cube.obj` — UV-mapped terrain and masonry meshes.

Models are imported at runtime with Assimp. The `asset_import` CTest validates runtime models, source animation data, and texture images.
