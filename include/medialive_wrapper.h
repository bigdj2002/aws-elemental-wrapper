#ifndef MEDIALIVEWRAPPER_H
#define MEDIALIVEWRAPPER_H

#include <aws/core/Aws.h>
#include <aws/medialive/MediaLiveClient.h>
#include <aws/medialive/model/CreateChannelRequest.h>
#include <aws/medialive/model/DeleteChannelRequest.h>
#include <aws/medialive/model/StartChannelRequest.h>
#include <aws/medialive/model/StopChannelRequest.h>
#include <aws/medialive/model/DescribeChannelRequest.h>
#include <iostream>

class MediaLiveWrapper {
public:
    MediaLiveWrapper();
    ~MediaLiveWrapper();

    Aws::String CreateChannel(const Aws::String& name);
    bool DeleteChannel(const Aws::String& channelId);
    bool StartChannel(const Aws::String& channelId);
    bool StopChannel(const Aws::String& channelId);
    void DescribeChannel(const Aws::String& channelId);

private:
    Aws::SDKOptions options;
    std::shared_ptr<Aws::MediaLive::MediaLiveClient> client;
};

#endif // MEDIALIVEWRAPPER_H
