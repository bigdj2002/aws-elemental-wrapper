#include "medialive_wrapper.h"

int main() {
    MediaLiveWrapper mediaLive;

    // Example usage
    Aws::String channelId = mediaLive.CreateChannel("TestChannel");
    if (!channelId.empty()) {
        mediaLive.DescribeChannel(channelId);
        mediaLive.StartChannel(channelId);
        mediaLive.StopChannel(channelId);
        mediaLive.DeleteChannel(channelId);
    }

    return 0;
}
