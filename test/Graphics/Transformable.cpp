#include <SFML/Graphics/Transformable.hpp>
#include "GraphicsUtil.hpp"

#include <doctest.h>

using doctest::Approx;

TEST_CASE("sf::Transformable class - [graphics]")
{
    SUBCASE("Construction")
    {
        const sf::Transformable transformable;
        CHECK(transformable.getPosition() == sf::Vector2f(0, 0));
        CHECK(transformable.getRotation() == 0);
        CHECK(transformable.getScale() == sf::Vector2f(1, 1));
        CHECK(transformable.getOrigin() == sf::Vector2f(0, 0));
        CHECK(transformable.getTransform() == sf::Transform());
        CHECK(transformable.getInverseTransform() == sf::Transform());
    }

    SUBCASE("Setters and getters")
    {
        sf::Transformable transformable;

        transformable.setPosition({3, 4});
        CHECK(transformable.getPosition() == sf::Vector2f(3, 4));

        transformable.setRotation(3.14f);
        CHECK(transformable.getRotation() == 3.14f);
        transformable.setRotation(540);
        CHECK(transformable.getRotation() == 180);
        transformable.setRotation(-72);
        CHECK(transformable.getRotation() == 288);

        transformable.setScale({5, 6});
        CHECK(transformable.getScale() == sf::Vector2f(5, 6));

        transformable.setOrigin({7, 8});
        CHECK(transformable.getOrigin() == sf::Vector2f(7, 8));

        sf::Transform transform;
        transform.translate(transformable.getPosition() - transformable.getOrigin());
        transform.rotate(transformable.getRotation(), transformable.getOrigin());
        transform.scale(transformable.getScale(), transformable.getOrigin());

        CHECK(transformable.getTransform().getMatrix()[0] == Approx(transform.getMatrix()[0]));
        CHECK(transformable.getTransform().getMatrix()[1] == Approx(transform.getMatrix()[1]));
        CHECK(transformable.getTransform().getMatrix()[2] == Approx(transform.getMatrix()[2]));
        CHECK(transformable.getTransform().getMatrix()[3] == Approx(transform.getMatrix()[3]));
        CHECK(transformable.getTransform().getMatrix()[4] == Approx(transform.getMatrix()[4]));
        CHECK(transformable.getTransform().getMatrix()[5] == Approx(transform.getMatrix()[5]));
        CHECK(transformable.getTransform().getMatrix()[6] == Approx(transform.getMatrix()[6]));
        CHECK(transformable.getTransform().getMatrix()[7] == Approx(transform.getMatrix()[7]));
        CHECK(transformable.getTransform().getMatrix()[8] == Approx(transform.getMatrix()[8]));
        CHECK(transformable.getTransform().getMatrix()[9] == Approx(transform.getMatrix()[9]));
        CHECK(transformable.getTransform().getMatrix()[10] == Approx(transform.getMatrix()[10]));
        CHECK(transformable.getTransform().getMatrix()[11] == Approx(transform.getMatrix()[11]));
        CHECK(transformable.getTransform().getMatrix()[12] == Approx(transform.getMatrix()[12]));
        CHECK(transformable.getTransform().getMatrix()[13] == Approx(transform.getMatrix()[13]));
        CHECK(transformable.getTransform().getMatrix()[14] == Approx(transform.getMatrix()[14]));
        CHECK(transformable.getTransform().getMatrix()[15] == Approx(transform.getMatrix()[15]));

        const sf::Transform inverse_transform = transform.getInverse();
        CHECK(transformable.getInverseTransform().getMatrix()[0] == Approx(inverse_transform.getMatrix()[0]));
        CHECK(transformable.getInverseTransform().getMatrix()[1] == Approx(inverse_transform.getMatrix()[1]));
        CHECK(transformable.getInverseTransform().getMatrix()[2] == Approx(inverse_transform.getMatrix()[2]));
        CHECK(transformable.getInverseTransform().getMatrix()[3] == Approx(inverse_transform.getMatrix()[3]));
        CHECK(transformable.getInverseTransform().getMatrix()[4] == Approx(inverse_transform.getMatrix()[4]));
        CHECK(transformable.getInverseTransform().getMatrix()[5] == Approx(inverse_transform.getMatrix()[5]));
        CHECK(transformable.getInverseTransform().getMatrix()[6] == Approx(inverse_transform.getMatrix()[6]));
        CHECK(transformable.getInverseTransform().getMatrix()[7] == Approx(inverse_transform.getMatrix()[7]));
        CHECK(transformable.getInverseTransform().getMatrix()[8] == Approx(inverse_transform.getMatrix()[8]));
        CHECK(transformable.getInverseTransform().getMatrix()[9] == Approx(inverse_transform.getMatrix()[9]));
        CHECK(transformable.getInverseTransform().getMatrix()[10] == Approx(inverse_transform.getMatrix()[10]));
        CHECK(transformable.getInverseTransform().getMatrix()[11] == Approx(inverse_transform.getMatrix()[11]));
        CHECK(transformable.getInverseTransform().getMatrix()[12] == Approx(inverse_transform.getMatrix()[12]));
        CHECK(transformable.getInverseTransform().getMatrix()[13] == Approx(inverse_transform.getMatrix()[13]));
        CHECK(transformable.getInverseTransform().getMatrix()[14] == Approx(inverse_transform.getMatrix()[14]));
        CHECK(transformable.getInverseTransform().getMatrix()[15] == Approx(inverse_transform.getMatrix()[15]));
    }

    SUBCASE("move()")
    {
        sf::Transformable transformable;
        CHECK(transformable.getPosition() == sf::Vector2f(0, 0));
        transformable.move({9, 10});
        CHECK(transformable.getPosition() == sf::Vector2f(9, 10));
        transformable.move({-15, 2});
        CHECK(transformable.getPosition() == sf::Vector2f(-6, 12));
    }

    SUBCASE("rotate()")
    {
        sf::Transformable transformable;
        CHECK(transformable.getRotation() == 0);
        transformable.rotate(15);
        CHECK(transformable.getRotation() == 15);
        transformable.rotate(360);
        CHECK(transformable.getRotation() == 15);
        transformable.rotate(-25);
        CHECK(transformable.getRotation() == 350);
        transformable.rotate(-720);
        CHECK(transformable.getRotation() == 350);
        transformable.rotate(-370);
        CHECK(transformable.getRotation() == 340);
    }

    SUBCASE("scale()")
    {
        sf::Transformable transformable;
        CHECK(transformable.getScale() == sf::Vector2f(1, 1));
        transformable.scale({2, 3});
        CHECK(transformable.getScale() == sf::Vector2f(2, 3));
        transformable.scale({2, 1});
        CHECK(transformable.getScale() == sf::Vector2f(4, 3));
        transformable.scale({-1, -1});
        CHECK(transformable.getScale() == sf::Vector2f(-4, -3));
    }
}
