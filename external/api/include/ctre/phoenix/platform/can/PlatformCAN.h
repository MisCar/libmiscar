#include "ctre/phoenix/cci/PlatformCAN_CCI.h"

namespace ctre {
namespace phoenix {
/** platform namespace */
namespace platform {
/** platform-can namespace */
namespace can {

/**
 * Configures the can interface for API
 */
class PlatformCAN {
public:
    /**
     * Set CAN interface
     * @param canInterface Can interface to set. Linux example: "can0".
     * @return ErrorCode generated by function
     */
    static int32_t SetCANInterface(const char * canInterface);

    /**
     * Starts all items in interface
     */
    static int32_t StartAll();

    /**
     * Destroys all items in interface
     */
    static int32_t DestroyAll();

    /**
     * Set Autocache state
     * @param state state of autocache
     */
    static void SetAutocacheLevel(ctre::phoenix::AutocacheState state);
};

}
}
}
}
