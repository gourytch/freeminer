/*
mesh.h
Copyright (C) 2010-2013 celeron55, Perttu Ahola <celeron55@gmail.com>
*/

/*
This file is part of Freeminer.

Freeminer is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Freeminer  is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Freeminer.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MESH_HEADER
#define MESH_HEADER

#include "irrlichttypes_extrabloated.h"
#include <string>

/*
	Create a new cube mesh.
	Vertices are at (+-scale.X/2, +-scale.Y/2, +-scale.Z/2).

	The resulting mesh has 6 materials (up, down, right, left, back, front)
	which must be defined by the caller.
*/
scene::IAnimatedMesh* createCubeMesh(v3f scale);

/*
	Create a new extruded mesh from a texture.
	Maximum bounding box is (+-scale.X/2, +-scale.Y/2, +-scale.Z).
	Thickness is in Z direction.

	The resulting mesh has 1 material which must be defined by the caller.
*/
scene::IAnimatedMesh* createExtrudedMesh(video::ITexture *texture,
		video::IVideoDriver *driver, v3f scale);

/*
	Multiplies each vertex coordinate by the specified scaling factors
	(componentwise vector multiplication).
*/
void scaleMesh(scene::IMesh *mesh, v3f scale);

/*
	Translate each vertex coordinate by the specified vector.
*/
void translateMesh(scene::IMesh *mesh, v3f vec);

/*
	Set a constant color for all vertices in the mesh
*/
void setMeshColor(scene::IMesh *mesh, const video::SColor &color);

/*
	Set the color of all vertices in the mesh.
	For each vertex, determine the largest absolute entry in
	the normal vector, and choose one of colorX, colorY or
	colorZ accordingly.
*/
void setMeshColorByNormalXYZ(scene::IMesh *mesh,
		const video::SColor &colorX,
		const video::SColor &colorY,
		const video::SColor &colorZ);

#endif
