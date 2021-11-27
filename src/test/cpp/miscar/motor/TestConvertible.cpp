#include "miscar/device/Falcon.h"
#include "miscar/motor/Convertible.h"

TEST(ConvertibleTest, CanConstruct) {
  miscar::Convertible<miscar::Falcon> convertible(miscar::Falcon(0));
}