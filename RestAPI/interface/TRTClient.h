#ifndef SonicCMS_TensorRT_TRTClient
#define SonicCMS_TensorRT_TRTClient

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"
#include "SonicCMS/Core/interface/SonicClientSync.h"
#include "SonicCMS/Core/interface/SonicClientPseudoAsync.h"
#include "SonicCMS/Core/interface/SonicClientAsync.h"

#include <vector>
#include <string>

template <typename Client>
class TRTClient : public Client {
	public:
		//constructor
		TRTClient(const edm::ParameterSet& params);
		unsigned ninput() const {return 1;}
		unsigned noutput() const {return 1000;}
		unsigned batchSize() const {return 1;}

		//for fillDescriptions
		static void fillPSetDescription(edm::ParameterSetDescription& iDesc) {
			edm::ParameterSetDescription descClient;
			descClient.add<std::string>("address");
			descClient.add<unsigned>("port");
			descClient.add<unsigned>("timeout");
			iDesc.add<edm::ParameterSetDescription>("Client",descClient);
		}

	protected:
		void predictImpl() override;

		//members
		std::string url_;
		unsigned timeout_;
};
typedef TRTClient<SonicClientSync<std::vector<float>>> TRTClientSync;
// typedef TRTClient<SonicClientPseudoAsync<std::vector<float>>> TRTClientPseudoAsync;
// typedef TRTClient<SonicClientAsync<std::vector<float>>> TRTClientAsync;

#endif
