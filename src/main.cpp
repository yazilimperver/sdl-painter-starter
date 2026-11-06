#include <sdl_painter/app/application.h>

namespace sp = sdl_painter;

// Your application: override the hooks you need, the framework owns the window,
// the event loop and timing.
class StarterApp : public sp::Application {
 public:
  using Application::Application;

 protected:
  void OnUpdate(float dt) override { mAngle += 45.0F * dt; }

  void OnRender(sp::Painter& painter) override {
    painter.Clear(sp::Color{24, 26, 33, 255});

    // A rotating rounded card: the brush fills, the pen outlines.
    painter.Save();
    painter.Translate(400.0F, 300.0F);
    painter.Rotate(mAngle);
    painter.SetBrush(sp::Brush(sp::Color{70, 130, 230, 255}));
    painter.SetPen(sp::Pen(sp::Color{200, 220, 255, 255}, 3.0F));
    painter.FillRoundedRect(-120.0F, -80.0F, 240.0F, 160.0F, 24.0F);
    painter.DrawRoundedRect(-120.0F, -80.0F, 240.0F, 160.0F, 24.0F);
    painter.Restore();

    // A dot that follows the mouse.
    painter.SetBrush(sp::Brush(sp::Color{255, 190, 60, 255}));
    painter.FillCircle(mMouseX, mMouseY, 12.0F);
  }

  void OnMouseMove(const sp::MouseMoveEvent& event) override {
    mMouseX = event.x;
    mMouseY = event.y;
  }

  void OnKeyDown(const sp::KeyEvent& event) override {
    if (event.key == sp::Key::kEscape) {
      Quit();
    }
  }

 private:
  float mAngle{0.0F};
  float mMouseX{400.0F};
  float mMouseY{300.0F};
};

int main() {
  sp::AppConfig config;
  config.title = "SDLPainter starter";
  config.width = 800;
  config.height = 600;

  StarterApp app(config);
  return app.Run();
}
