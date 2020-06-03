/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Input.hpp
*/

#ifndef INDIESTUDIO_INPUT_HPP
#define INDIESTUDIO_INPUT_HPP

#include "../Event.hpp"

/**
 * @file Input.hpp
 * @brief Input Class
 * @author Lucas.M Mattéo.F
 * @version 1.0
 * @date 03 june 2020
 */

/**
 * @namespace ecs::event
 */
namespace ecs::event {

/**
 * @class Input
 * @brief Input event good for manage user entries.
 */
class Input : public ecs::Event {
  public:
    /**
     * @brief Constructor
     * Constructor of Input Class.
     * @param input : String of input(s).
     */
    explicit Input(std::string input);
    /**
     * @brief Destructor
     * It's a default destructor because the garbage collector will take care of the rest.
     */
    ~Input() override;

  public:
    std::string input; /**< String of input(s). */
};

} // namespace event

#endif // INDIESTUDIO_INPUT_HPP
