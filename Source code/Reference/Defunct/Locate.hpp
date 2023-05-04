#pragma once

// gameprogrammingpatterns.com/service-locator.html
class Game;
class OS;
class Graphics;
class Input;

class Locate
{
    private:
    // These are Globals ! :(
        static inline Game     * game_     { nullptr };
        static inline OS       * os_       { nullptr };
        static inline Graphics * graphics_ { nullptr };
        static inline Input    * input_    { nullptr };

        //static inline Write * write{ nullptr };

    public:

        static void   game( Game * game ) { game_ = game; }
        static Game & game()              { return *game_; }

        static void       graphics( Graphics * graphics ) { graphics_ = graphics; }
        static Graphics & graphics() { return *graphics_; }

        static void os( OS * os ) { os_ = os; }
        static OS & os() { return * os_; }

        static void    input( Input * input ) { input_ = input; }
        static Input & input()                { return * input_; }

        //static void        write( write_d2d * in_write ) {  write = in_write; }
        //static write_d2d & write()                       { return *write; }

        ~Locate()
        {
            graphics_ = nullptr;
            os_ = nullptr;
            game_ = nullptr;
        }
};