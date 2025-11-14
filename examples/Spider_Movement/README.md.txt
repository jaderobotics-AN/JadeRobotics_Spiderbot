and click **Install**.

### **2. Manual Installation**
1. Download the repository ZIP  
2. In Arduino IDE: **Sketch → Include Library → Add .ZIP Library**  
3. Select the downloaded ZIP file

---

## 🧩 Basic Example

```cpp
#include <movements.h>

int servoPins[NUM_SERVOS] = {3,5,6,9,10,11,12,13};

void setup() {
  initServos(servoPins);
  neutralStand();
}

void loop() {
  walkForward();
  rotateLeft();
}
