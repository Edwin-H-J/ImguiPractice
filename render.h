//
// Created by jhas on 2022/12/11.
//

#ifndef IMGUIPRACTICE_RENDER_H
#define IMGUIPRACTICE_RENDER_H
#include <memory>
class Renderable {
public:
    virtual void render() = 0;
    virtual ~Renderable()= default;
};
#endif //IMGUIPRACTICE_RENDER_H
