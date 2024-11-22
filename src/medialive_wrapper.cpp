#include "medialive_wrapper.h"

MediaLiveWrapper::MediaLiveWrapper() {
    Aws::InitAPI(options);
    client = Aws::MakeShared<Aws::MediaLive::MediaLiveClient>("MediaLiveWrapper");
}

MediaLiveWrapper::~MediaLiveWrapper() {
    Aws::ShutdownAPI(options);
}

Aws::String MediaLiveWrapper::CreateChannel(const Aws::String& name) {
    Aws::MediaLive::Model::CreateChannelRequest request;
    request.SetName(name);

    auto outcome = client->CreateChannel(request);
    if (outcome.IsSuccess()) {
        std::cout << "Channel created: " << outcome.GetResult().GetChannelId() << std::endl;
        return outcome.GetResult().GetChannelId();
    } else {
        std::cerr << "Error creating channel: " << outcome.GetError().GetMessage() << std::endl;
        return "";
    }
}

bool MediaLiveWrapper::DeleteChannel(const Aws::String& channelId) {
    Aws::MediaLive::Model::DeleteChannelRequest request;
    request.SetChannelId(channelId);

    auto outcome = client->DeleteChannel(request);
    if (outcome.IsSuccess()) {
        std::cout << "Channel deleted: " << channelId << std::endl;
        return true;
    } else {
        std::cerr << "Error deleting channel: " << outcome.GetError().GetMessage() << std::endl;
        return false;
    }
}

bool MediaLiveWrapper::StartChannel(const Aws::String& channelId) {
    Aws::MediaLive::Model::StartChannelRequest request;
    request.SetChannelId(channelId);

    auto outcome = client->StartChannel(request);
    if (outcome.IsSuccess()) {
        std::cout << "Channel started: " << channelId << std::endl;
        return true;
    } else {
        std::cerr << "Error starting channel: " << outcome.GetError().GetMessage() << std::endl;
        return false;
    }
}

bool MediaLiveWrapper::StopChannel(const Aws::String& channelId) {
    Aws::MediaLive::Model::StopChannelRequest request;
    request.SetChannelId(channelId);

    auto outcome = client->StopChannel(request);
    if (outcome.IsSuccess()) {
        std::cout << "Channel stopped: " << channelId << std::endl;
        return true;
    } else {
        std::cerr << "Error stopping channel: " << outcome.GetError().GetMessage() << std::endl;
        return false;
    }
}

void MediaLiveWrapper::DescribeChannel(const Aws::String& channelId) {
    Aws::MediaLive::Model::DescribeChannelRequest request;
    request.SetChannelId(channelId);

    auto outcome = client->DescribeChannel(request);
    if (outcome.IsSuccess()) {
        std::cout << "Channel description: " << outcome.GetResult().GetArn() << std::endl;
    } else {
        std::cerr << "Error describing channel: " << outcome.GetError().GetMessage() << std::endl;
    }
}
