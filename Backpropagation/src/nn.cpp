/* 
A simpler backpropagation network 
Created By: Shiva Bhusal, BGSU 
Based on a Video Tutorial 
*/ 

#include<vector>
#include<iostream>

class Neuron{}; 
typedef std::vector<Neuron> Layer;

class Net
{
public:
	Net(const std::vector<unsigned> &topology); 
	void feedForward(const std::vector<double> &inputVals){}; 
	void backProp(const std::vector<double> &targetVals){}; 
	void getResults(std::vector<double> &resultVals) const {}; 

private: 
	std::vector<Layer> m_layers;
}; 

Net::Net(const std::vector<unsigned> &topology)
{
	unsigned numLayers=topology.size(); 
	for (unsigned layerNum=0; layerNum<=numLayers; ++layerNum){
		m_layers.push_back(Layer()); 

		// We have got a new layer and now we need an inner loop to add nodes to this layer. 

		for (unsigned neuronNum=0; neuronNum<=topology[layerNum]; ++neuronNum){
			m_layers.back().push_back(Neuron()); 
			std::cout<<"Made a Neuron !"<<std::endl; 
		}
	}
}

int main()
{
	// Eg. 3,2,1 
	std::vector<unsigned> topology;
	topology.push_back(3); 
	topology.push_back(2); 
	topology.push_back(1); 
	Net myNet(topology); 

	std::vector<double> inputVals;
	myNet.feedForward(inputVals);

	std::vector<double> targetVals;
	myNet.backProp(targetVals); 

    std::vector<double> resultVals;
	myNet.getResults(resultVals); 


}