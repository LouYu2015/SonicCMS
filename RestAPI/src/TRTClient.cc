#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "SonicCMS/RestAPI/interface/TRTClient.h"
#include "SonicCMS/RestAPI/interface/BaseRestClient.h"

#include <string>
#include <chrono>
#include <exception>
#include <iostream>

template <typename Client>
TRTClient<Client>::TRTClient(const edm::ParameterSet& params) :
	Client(),
	url_(std::string() + "http://" + params.getParameter<std::string>("address")+":"
		+std::to_string(params.getParameter<unsigned>("port")) + "/predict")
{
}

template <typename Client>
void TRTClient<Client>::predictImpl(){
	std::cout << "prediction to " + url_ << std::endl;
	auto t2 = std::chrono::high_resolution_clock::now();

	RestAPIClient::BaseClient client(this->input(), url_);
	client.getReply();

	auto t3 = std::chrono::high_resolution_clock::now();
	edm::LogInfo("TRTClient") << "Remote time: " << std::chrono::duration_cast<std::chrono::microseconds>(t3-t2).count();
}

//explicit template instantiations
template class TRTClient<SonicClientSync<std::vector<float>>>;
// template class TRTClient<SonicClientAsync<std::vector<float>>>;
// template class TRTClient<SonicClientPseudoAsync<std::vector<float>>>;
