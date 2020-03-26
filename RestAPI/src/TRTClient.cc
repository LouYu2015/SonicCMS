#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "SonicCMS/RestAPI/interface/TRTClient.h"

#include <string>
#include <chrono>
#include <exception>

template <typename Client>
TRTClient<Client>::TRTClient(const edm::ParameterSet& params) :
	Client(),
	url_(params.getParameter<std::string>("address")+":"+std::to_string(params.getParameter<unsigned>("port")))
{
}

template <typename Client>
void TRTClient<Client>::predictImpl(){

	//blocking call
	// auto t2 = std::chrono::high_resolution_clock::now();
	// std::map<std::string, std::unique_ptr<nic::InferContext::Result>> results;
	// nic::Error err0 = context_->Run(&results);
	// auto t3 = std::chrono::high_resolution_clock::now();
	// edm::LogInfo("TRTClient") << "Remote time: " << std::chrono::duration_cast<std::chrono::microseconds>(t3-t2).count();
	// getResults(results.begin()->second);
}

//explicit template instantiations
template class TRTClient<SonicClientSync<std::vector<float>>>;
// template class TRTClient<SonicClientAsync<std::vector<float>>>;
// template class TRTClient<SonicClientPseudoAsync<std::vector<float>>>;
