/* 
A simpler backpropagation network 
Created By: Shiva Bhusal, BGSU 
Based on a Video Tutorial 
*/ 

#include<vector>
#include<iostream>
#include<cstdlib>
#include<cassert>
#include<cmath>

struct Connection
{
	double weight;
	double deltaWeight; 
};

class Neuron{}; 
typedef std::vector<Neuron> Layer;

class Neuron 
{
public:
	Neuron(unsigned numOutputs, unsigned myIndex); 
	void setOutputVal(double val){m_outputVal=val;}; 
	double getOutputVal(void) const {return m_outputVal;}; 
	void feedForward(const Layer &prevLayer); 
	void calcOutputsGradients(double targetVals); 
	void calcHiddenGradients(const Layer &nextLayer); 

private: 
	static double transferFunction(double x); 
	static double transferFunctionDerivative(double x); 
	static double randomWeight(void){return rand()/double(RAND_MAX);}; 
	double sumDOW(const Layer &nextLayer); 
	double m_outputVal; 
	std::vector<Connection> m_outputWeights;
	unsigned m_myIndex; 
	double m_outputVal; 

}

double Neuron::sumDOW(const Layer &nextLayer) const {
	double sum=0.0; 

	for (unsigned n=0; n<nextLayer.size()-1,++n)
	{
		sum +=m_outputWeights[n].weight*nextLayer[n].m_gradient; 
	}

	return sum; 
}

void Neuron::calcHiddenGradients(const Layer &nextLayer)
{
	double dow=sumDOW(nextLayer); 
	m_gradient=dow*Neuron::transferFunctionDerivative(m_outputVal); 

}

void Neuron::calcOutputsGradients(double targetVal)
{
	double delta=targetVal-m_outputVal; 
	m_gradient=delta * Neuron::transferFunctionDerivative(m_outputVal); 
}

double Neuron:: transferFunction(double x)
{
	return tanh(x); 

}

double Neuron::transferFunctionDerivative(double x)
{
	return 1-x*x; 
}

void Neuron::feedForward(const Layer &prevLayer)
{
	double sum=0.0; 

	for (unsigned n=0;n<prevLayer.size();++n)
	{
		sum+=prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight; 
	}
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
	for (unsigned c=0;c<numOutputs;++c){
		m_outputWeights.push_back(Connection()); 
		m_outputWeights.back().weight=randomWeight(); 
	}
	m_myIndex=myIndex; 
}

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

void Net::backProp(const std::vector<double> targetVals)
{
	Layer &outputLayer=m_layers.back(); 
	m_error=0.0; 

	for (unsigned n=0;n<outputLayer.size()-1, ++n){
		double delta=targetVals[n]-outputLayer[n].getOutputVal(); 
		m_error+=delta*delta; 
	}
	m_error/=outputLayer.size()-1; 
	m_error=sqrt(m_error); 

	m_recentAverageError=(m_recentAverageError*m_recentAverageSmoothingFactor+m_error)
	/(m_recentAverageSmoothingFactor+1.0); 

	for (unsigned n=0; n<outputLayer.size()-1;++n){
		outputLayer[n].calcOutputsGradients(targetVals[n]); 
	}

	for (unsigned layerNum=m_layers.size()-2; layerNum>0; --layerNum){
		Layer &hiddenLayer=m_layers[layerNum]; 
		Layer &nextLayer=m_layers[layerNum+1]; 

		for (unsigned n=0; n<hiddenLayer.size();++n){
			hiddenLayer[n].calcHiddenGradients(nextLayer); 
		}
	}

	for (unsigned layerNum=m_layers.size()-1; layerNum>0; --layerNum){
		Layer &layer=m_layers[layerNum]; 
		Layer &prevLayer=m_layers[layerNum-1];

		for (unsigned n=0; n<layer.size()-1;++n){
			layer[n].updateInputWeights(prevLayer); 
		} 

	}
}

void Net::feedForward(const std::vector<double> &inputVals)
{
	assert(inputVals.size()==m_layers[0].size()-1); 

	// Assign the input values 

	for (unsigned i=0; i<inputVals.size();++i)
	{
		m_layers[0][i].setOutputVal(inputVals[i]); 
	}

	// forward propagate 
	for (unsigned layerNum=1; layerNum<=m_layers.size();++layerNum){
		Layer &prevLayer=m_layers[layerNum-1]; 
		for (unsigned n=0; n<n_layers[layerNum].size()-1;++n){
			m_layers[layerNum][n].feedForward(prevLayer); 
		}
	}
	m_outputVal=Neuron::transferFunction(sum); 
}

Net::Net(const std::vector<unsigned> &topology)
{
	unsigned numLayers=topology.size(); 
	for (unsigned layerNum=0; layerNum<=numLayers; ++layerNum){
		m_layers.push_back(Layer()); 
		unsigned numOutputs=(layerNum==topology.size()-1 ?0:topology[layerNum+1]); 

		// We have got a new layer and now we need an inner loop to add nodes to this layer. 

		for (unsigned neuronNum=0; neuronNum<=topology[layerNum]; ++neuronNum){
			m_layers.back().push_back(Neuron(numOutputs)); 
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