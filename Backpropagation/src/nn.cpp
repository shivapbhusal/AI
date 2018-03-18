/* 
A simpler backpropagation network 
Created By: Shiva Bhusal, BGSU 
Based on a Video Tutorial 
*/ 

#include<vector>

class Neuron; 
typedef std::vector<Neuron> Layer;

class Net
{
public:
	Net(const std::vector<unsigned> &topology); 
	void feedForward(const std::std::vector<double> &inputVals); 
	void backProp(const std::vector<double> &targetVals); 
	void getResults(std::vector<double> &resultVals) const; 

private: 
	std::vector<Layer> m_layers;
}; 

Net::Net(const std::vector<unsigned> &topology)
{
	unsigned numLayers=topology.size(); 
}

int main()
{
	// Eg. 3,2,1 
	std::vector<unsigned> topology;
	Net myNet(topology); 

	std::vector<double> inputVals;
	myNet.feedForward(inputVals);

	std::vector<double> targetVals;
	myNet.backProp(targetVals); 

    std::vector<double> resultVals;
	myNet.getResults(resultVals); 


}