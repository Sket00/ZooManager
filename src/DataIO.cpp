#include "DataIO.hpp"

namespace ws {

    template <typename T>
    T DataIO::safeInput(const std::string& datain) {
        T value;
        std::cout << datain;
        while (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. " << datain << "\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        return value;
    }

    std::unique_ptr<Animal> DataIO::createAnimalSelection() {
        int choice = safeInput<int>("1. Lion\n2. Eagle\n3. Snake\nSelect type: ");
        
        std::unique_ptr<Animal> animal = nullptr;

        try {
            switch(choice) {
                case 1: {
                    auto lion = std::make_unique<Lion>();
                    inputAnimalData(lion.get());
                    inputMammalData(lion.get());
                    inputLionData(lion.get());
                    animal = std::move(lion);
                    break;
                }
                case 2: {
                    auto eagle = std::make_unique<Eagle>();
                    inputAnimalData(eagle.get());
                    inputBirdData(eagle.get());
                    inputEagleData(eagle.get());
                    animal = std::move(eagle);
                    break;
                }
                case 3: {
                    auto snake = std::make_unique<Snake>();
                    inputAnimalData(snake.get());
                    inputReptileData(snake.get());
                    inputSnakeData(snake.get());
                    animal = std::move(snake);
                    break;
                }
                default:
                    std::cout << "Invalid selection.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error creating animal: " << e.what() << "\n";
            return nullptr;
        }
        return animal;
    }

    void DataIO::inputAnimalData(Animal* animal) {
        std::cout << "--- General Animal Info ---\n";
        animal->setName(safeInput<std::string>("Name: "));
        
        while (true) {
            try {
                animal->setGender(safeInput<std::string>("Gender (M/F): "));
                break;
            } catch (const std::exception& e) { std::cout << e.what() << "\n"; }
        }

        while (true) {
            try {
                animal->setAge(safeInput<int>("Age: "));
                break;
            } catch (const std::exception& e) { std::cout << e.what() << "\n"; }
        }

        while (true) {
            try {
                animal->setWeight(safeInput<double>("Weight (kg): "));
                break;
            } catch (const std::exception& e) { std::cout << e.what() << "\n"; }
        }

        while (true) {
            std::string dateStr = safeInput<std::string>("Arrival Date (DD.MM.YYYY): ");
            try {
                animal->setArrivalDate(Date(dateStr));
                break;
            } catch (const std::exception& e) {
                std::cout << "Invalid date: " << e.what() << ". Please try again.\n";
            }
        }
    }

    void DataIO::inputMammalData(Mammal* mammal) {
        std::cout << "--- Mammal Info ---\n";
        mammal->setHasFur(safeInput<bool>("Has Fur (1/0): "));
        mammal->setIsAggressive(safeInput<bool>("Is Aggressive (1/0): "));
        mammal->setDietType(safeInput<std::string>("Diet Type: "));
    }

    void DataIO::inputBirdData(Bird* bird) {
        std::cout << "--- Bird Info ---\n";
        while(true) {
            try {
                bird->setWingSpan(safeInput<double>("Wingspan (m): "));
                break;
            } catch(const std::exception& e) { std::cout << e.what() << "\n"; }
        }
        bird->setCanFly(safeInput<bool>("Can Fly (1/0): "));
        bird->setBeakColor(safeInput<std::string>("Beak Color: "));
    }

    void DataIO::inputReptileData(Reptile* reptile) {
        std::cout << "--- Reptile Info ---\n";
        reptile->setIsVenomous(safeInput<bool>("Is Venomous (1/0): "));
        reptile->setScaleTexture(safeInput<std::string>("Scale Texture: "));
        reptile->setRequiresHeatLamp(safeInput<bool>("Requires Heat Lamp (1/0): "));
    }

    void DataIO::inputLionData(Lion* lion) {
        std::cout << "--- Lion Info ---\n";
        while(true) {
            try {
                lion->setManeLength(safeInput<double>("Mane Length (cm): "));
                break;
            } catch(const std::exception& e) { std::cout << e.what() << "\n"; }
        }
        while(true) {
            try {
                lion->setPrideSize(safeInput<int>("Pride Size: "));
                break;
            } catch(const std::exception& e) { std::cout << e.what() << "\n"; }
        }
        while(true) {
            try {
                lion->setRoarVolume(safeInput<int>("Roar Volume (dB): "));
                break;
            } catch(const std::exception& e) { std::cout << e.what() << "\n"; }
        }
    }

    void DataIO::inputEagleData(Eagle* eagle) {
        std::cout << "--- Eagle Info ---\n";
        while(true) {
            try {
                eagle->setVisionRange(safeInput<double>("Vision Range (m): "));
                break;
            } catch(const std::exception& e) { std::cout << e.what() << "\n"; }
        }
        while(true) {
            try {
                eagle->setDivingSpeed(safeInput<double>("Diving Speed (km/h): "));
                break;
            } catch(const std::exception& e) { std::cout << e.what() << "\n"; }
        }
        eagle->setIsTrained(safeInput<bool>("Is Trained (1/0): "));
    }

    void DataIO::inputSnakeData(Snake* snake) {
        std::cout << "--- Snake Info ---\n";
        while(true) {
            try {
                snake->setLength(safeInput<double>("Length (m): "));
                break;
            } catch(const std::exception& e) { std::cout << e.what() << "\n"; }
        }
        snake->setIsConstrictor(safeInput<bool>("Is Constrictor (1/0): "));
        while(true) {
            try {
                snake->setSheddingFrequency(safeInput<int>("Shedding Frequency (days): "));
                break;
            } catch(const std::exception& e) { std::cout << e.what() << "\n"; }
        }
    }

    void DataIO::editAnimal(Animal* animal) {
        if (!animal) return;

        if (auto lion = dynamic_cast<Lion*>(animal)) {
            editLionMenu(lion);
        } else if (auto eagle = dynamic_cast<Eagle*>(animal)) {
            editEagleMenu(eagle);
        } else if (auto snake = dynamic_cast<Snake*>(animal)) {
            editSnakeMenu(snake);
        } else {
            editAnimalMenu(animal);
        }
    }

    void DataIO::editAnimalMenu(Animal* animal) {
        bool editing = true;
        while (editing) {
            std::cout << "\n--- Edit Animal: " << animal->getName() << " ---\n";
            std::cout << "1. Name (" << animal->getName() << ")\n";
            std::cout << "2. Gender (" << animal->getGender() << ")\n";
            std::cout << "3. Age (" << animal->getAge() << ")\n";
            std::cout << "4. Weight (" << animal->getWeight() << ")\n";
            std::cout << "0. Back\n";
            
            int choice = safeInput<int>("Select: ");
            try {
                switch(choice) {
                    case 1: animal->setName(safeInput<std::string>("New Name: ")); break;
                    case 2: animal->setGender(safeInput<std::string>("New Gender: ")); break;
                    case 3: animal->setAge(safeInput<int>("New Age: ")); break;
                    case 4: animal->setWeight(safeInput<double>("New Weight: ")); break;
                    case 0: editing = false; break;
                    default: std::cout << "Invalid choice\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }
    }

    void DataIO::editLionMenu(Lion* lion) {
        bool editing = true;
        while (editing) {
            std::cout << "\n--- Edit Lion ---\n";
            std::cout << "1. General Animal Info\n";
            std::cout << "2. Mammal Info (Fur/Aggro/Diet)\n";
            std::cout << "3. Mane Length (" << lion->getManeLength() << ")\n";
            std::cout << "4. Pride Size (" << lion->getPrideSize() << ")\n";
            std::cout << "5. Roar Volume (" << lion->getRoarVolume() << ")\n";
            std::cout << "0. Finish\n";

            int choice = safeInput<int>("Select: ");
            try {
                switch(choice) {
                    case 1: editAnimalMenu(lion); break;
                    case 2: editMammalMenu(lion); break;
                    case 3: lion->setManeLength(safeInput<double>("New Mane: ")); break;
                    case 4: lion->setPrideSize(safeInput<int>("New Pride Size: ")); break;
                    case 5: lion->setRoarVolume(safeInput<int>("New Volume: ")); break;
                    case 0: editing = false; break;
                    default: std::cout << "Invalid choice\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }
    }

    void DataIO::editMammalMenu(Mammal* mammal) {
        bool editing = true;
        while(editing) {
            std::cout << "\n--- Edit Mammal Info ---\n";
            std::cout << "1. Has Fur (" << mammal->getHasFur() << ")\n";
            std::cout << "2. Aggressive (" << mammal->getIsAggressive() << ")\n";
            std::cout << "3. Diet (" << mammal->getDietType() << ")\n";
            std::cout << "0. Back\n";
            
            int choice = safeInput<int>("Select: ");
            switch(choice) {
                case 1: mammal->setHasFur(safeInput<bool>("Has Fur (1/0): ")); break;
                case 2: mammal->setIsAggressive(safeInput<bool>("Aggressive (1/0): ")); break;
                case 3: mammal->setDietType(safeInput<std::string>("New Diet: ")); break;
                case 0: editing = false; break;
                default: std::cout << "Invalid choice\n";
            }
        }
    }

    void DataIO::editEagleMenu(Eagle* eagle) {
        bool editing = true;
        while (editing) {
            std::cout << "\n--- Edit Eagle ---\n";
            std::cout << "1. General Animal Info\n";
            std::cout << "2. Bird Info (Wings/Fly/Beak)\n";
            std::cout << "3. Vision Range (" << eagle->getVisionRange() << ")\n";
            std::cout << "4. Diving Speed (" << eagle->getDivingSpeed() << ")\n";
            std::cout << "5. Trained (" << eagle->getIsTrained() << ")\n";
            std::cout << "0. Finish\n";

            int choice = safeInput<int>("Select: ");
            try {
                switch(choice) {
                    case 1: editAnimalMenu(eagle); break;
                    case 2: editBirdMenu(eagle); break;
                    case 3: eagle->setVisionRange(safeInput<double>("New Vision: ")); break;
                    case 4: eagle->setDivingSpeed(safeInput<double>("New Speed: ")); break;
                    case 5: eagle->setIsTrained(safeInput<bool>("Is Trained (1/0): ")); break;
                    case 0: editing = false; break;
                    default: std::cout << "Invalid choice\n";
                }
            } catch (const std::exception& e) { std::cout << "Error: " << e.what() << "\n"; }
        }
    }

    void DataIO::editBirdMenu(Bird* bird) {
        bool editing = true;
        while(editing) {
            std::cout << "\n--- Edit Bird Info ---\n";
            std::cout << "1. Wingspan\n2. Can Fly\n3. Beak Color\n0. Back\n";
            int choice = safeInput<int>("Select: ");
            switch(choice) {
                case 1: bird->setWingSpan(safeInput<double>("New Wingspan: ")); break;
                case 2: bird->setCanFly(safeInput<bool>("Can Fly (1/0): ")); break;
                case 3: bird->setBeakColor(safeInput<std::string>("New Beak Color: ")); break;
                case 0: editing = false; break;
                default: std::cout << "Invalid\n";
            }
        }
    }

    void DataIO::editSnakeMenu(Snake* snake) {
        bool editing = true;
        while (editing) {
            std::cout << "\n--- Edit Snake ---\n";
            std::cout << "1. General Animal Info\n";
            std::cout << "2. Reptile Info\n";
            std::cout << "3. Length\n4. Constrictor\n5. Shedding\n0. Finish\n";
            
            int choice = safeInput<int>("Select: ");
            try {
                switch(choice) {
                    case 1: editAnimalMenu(snake); break;
                    case 2: editReptileMenu(snake); break;
                    case 3: snake->setLength(safeInput<double>("New Length: ")); break;
                    case 4: snake->setIsConstrictor(safeInput<bool>("Constrictor (1/0): ")); break;
                    case 5: snake->setSheddingFrequency(safeInput<int>("New Shedding: ")); break;
                    case 0: editing = false; break;
                    default: std::cout << "Invalid\n";
                }
            } catch (const std::exception& e) { std::cout << "Error: " << e.what() << "\n"; }
        }
    }

    void DataIO::editReptileMenu(Reptile* reptile) {
        bool editing = true;
        while(editing) {
            std::cout << "\n--- Edit Reptile Info ---\n";
            std::cout << "1. Venomous\n2. Texture\n3. Heat Lamp\n0. Back\n";
            int choice = safeInput<int>("Select: ");
            switch(choice) {
                case 1: reptile->setIsVenomous(safeInput<bool>("Venomous (1/0): ")); break;
                case 2: reptile->setScaleTexture(safeInput<std::string>("Texture: ")); break;
                case 3: reptile->setRequiresHeatLamp(safeInput<bool>("Heat Lamp (1/0): ")); break;
                case 0: editing = false; break;
                default: std::cout << "Invalid\n";
            }
        }
    }

}