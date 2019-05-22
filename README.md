# pge

"Predictive Game Engine.  This is a physics engine which can coexist
with PyGame or run in batch mode with Python.  It is implemented in
Modula-2, C++, Python and maxima.  Internally it predicts the time
of next collision rather than test for a collision every frame."

This fork contains a modified version of PGE with:
- Per object gravity & elasticity
- Rotation & movement of static objects
- Transparancy (using alpha) of both foreground & background objects
- Poly6 and Poly10 support

The 'coursework' folder (in 'examples') features a pan flip game, where the user must move the pan to bounce the ball onto plate on the table. This example uses all of the modifications to the engine.
