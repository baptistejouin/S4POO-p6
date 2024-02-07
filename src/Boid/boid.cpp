#include "Boid/boid.hpp"

glm::vec2 get_random_velocity()
{
    return glm::vec2{p6::random::number(-1.f, 1.f), p6::random::number(-1.f, 1.f)};
}

// constructor
Boid::Boid(p6::Color color, glm::vec2 position, glm::vec2 velocity)
    : color(color)
    , position(position)
    , velocity(velocity)
{
}

Boid::Boid()
    : color(p6::Color{0.0f, 1.0f, 1.0f})
    , position(glm::vec2{0.0f, 0.0f})
    , velocity(glm::vec2{get_random_velocity()})
{}

void Boid::update(float delta_time)
{
    position += velocity * delta_time;
}

void Boid::draw(p6::Context& ctx) const
{
    ctx.fill = color;
    ctx.circle(p6::Center(position), p6::Radius(0.01f));
}