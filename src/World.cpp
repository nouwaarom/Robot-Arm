//
// Created by elbert on 20/01/17.
//
#include "World.h"
#include "Camera.h"

World* _eventHandlingWorld = nullptr;

// Non class functions
void setGlutEventHandler(World* world, int argc, char** argv)
{
    glutInit(&argc,argv);

    _eventHandlingWorld = world;
    // Set callbacks
    glutDisplayFunc(_display);
    glutReshapeFunc(_reshape);
    glutIdleFunc(_idle);
    glutKeyboardFunc(_keycontrol);
    glutMouseFunc(_mousecontrol);
}

void _display()
{
    if (_eventHandlingWorld) {
        _eventHandlingWorld->display();
    }
}

void _reshape(int w, int h)
{
    if (_eventHandlingWorld) {
        _eventHandlingWorld->reshape(w, h);
    }
}

void _idle()
{
    if (_eventHandlingWorld) {
        _eventHandlingWorld->idle();
    }
    glutPostRedisplay();
}

void _keycontrol(unsigned char key, int x, int y)
{
    if (_eventHandlingWorld) {
        _eventHandlingWorld->getInputManager()->keyCallback(key, x, y);
    }
}

void _mousecontrol(int eventType, int startEnd, int x, int y)
{
    // y is inverted
    if (_eventHandlingWorld) {
        _eventHandlingWorld->getInputManager()->mouseCallback(eventType, startEnd, x, y);
    }
}

World::World(InputManager* inputManager)
{
    _inputManager = inputManager;
}

void World::start()
{
    glutMainLoop();
}

void World::update(int deltaTime)
{
    for (WorldObject* object : _objects) {
        object->update(deltaTime);
    }
}

void World::display() const
{
    Camera* camera = dynamic_cast<Camera*>(getObjectById('C'));

    camera->predraw();
    for (WorldObject* object : _objects) {
        object->draw();
    }
    camera->postdraw();
}

void World::reshape(int w, int h)
{
    // Search for camera object, and pass to camera object
    Camera* camera = dynamic_cast<Camera*>(getObjectById('C'));
    camera->reshape(w, h);
}

void World::idle()
{
    // Calculate delta-time
    static int lastTime = 0;
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    int deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    update(deltaTime);
}

InputManager* World::getInputManager()
{
    return _inputManager;
}

void World::addObject(WorldObject *object)
{
    _objects.push_back(object);
    object->setWorld(this);
}

WorldObject* World::getObjectById(char id) const
{
    for (WorldObject* object : _objects) {
        if (object->getId() == id) {
            return object;
        }
    }
    return nullptr;
}
