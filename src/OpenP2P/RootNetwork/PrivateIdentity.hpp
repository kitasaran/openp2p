#ifndef OPENP2P_ROOTNETWORK_PRIVATEIDENTITY_HPP
#define OPENP2P_ROOTNETWORK_PRIVATEIDENTITY_HPP

#include <stdint.h>

#include <OpenP2P/RootNetwork/Key.hpp>
#include <OpenP2P/RootNetwork/Packet.hpp>

namespace OpenP2P {

	namespace RootNetwork {
	
		struct PacketSignature {
			Buffer signature;
			PublicKey publicKey;
		};
		
		class PrivateIdentity {
			public:
				PrivateIdentity(const PrivateKey&, uint64_t packetCount = 0);
				
				inline uint64_t packetCount() {
					return packetCount_;
				}
				
				inline PrivateKey privateKey() {
					return privateKey_;
				}
				
				PacketSignature sign(const Packet&);
				
			private:
				PrivateKey privateKey_;
				uint64_t packetCount_;
				
		};
		
	}
	
}

#endif
