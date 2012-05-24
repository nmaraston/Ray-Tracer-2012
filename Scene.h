#ifndef _SCENE_H_
#define _SCENE_H_


#include <vector>

#include "Surface.h"
#include "Light.h"
#include "Spectrum.h"


/*
 * A Scene is defined by a list of surfaces (objects that the rays intersect), a list of light
 * sources and a background colour.
 */
class Scene {

	public:

		// Constructor.
		inline Scene(const Spectrum& background_colour = Spectrum::BLACK);

		// To build the scene.
		inline void add_surface(Surface* surface);
		inline void add_light(Light* light);

		// Scene access.
		inline const std::vector<Surface*>& get_surfaces(void) const;
		inline const std::vector<Light*>& get_lights(void) const;
		inline const Spectrum& get_background_colour(void) const;

	private:
		
		// A collection of surfaces that in the scene.
		std::vector<Surface*> surfaces_;

		// A collection of light sources in the scene.
		std::vector<Light*> lights_;

		// Pixel colour used when a ray does not intersect any surface.
		Spectrum background_colour_;

};


// Inline implementations:


/*
 * Constructs a new scene with the given background colour or black if no colour is provided.
 */
inline
Scene::Scene(const Spectrum& background_colour)
	: background_colour_(background_colour)
{}


/*
 * Adds a surface pointed to by p_surface to this scenes list of surfaces.
 */
inline
void Scene::add_surface(Surface* surface)
{
	surfaces_.push_back(surface);
}


/*
 * Adds a light source pointed to by p_light to this scenes list of light sources.
 */
inline
void Scene::add_light(Light* light)
{
	lights_.push_back(light);
}


/*
 * Returns this scenes list of surfaces.
 */
inline
const std::vector<Surface*>& Scene::get_surfaces(void) const
{
	return surfaces_;
}


/*
 * Returns this scenes list of light sources.
 */
inline
const std::vector<Light*>& Scene::get_lights(void) const
{
	return lights_;
}


/*
 * Returns the background colour of this scene.
 */
inline
const Spectrum& Scene::get_background_colour(void) const
{
	return background_colour_;
}


#endif // _SCENE_H_
