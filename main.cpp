#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <iostream>
#include <vector>

using namespace std;

struct position{int x, y;};

class Platform{
	sf::RenderWindow* window;
	sf::Texture pieceTexture;
	sf::Sprite pieceSprite;
	public:
		position pos;

		Platform(){
			int random_num = rand()%400;
			int random2 = (rand()%300)*(-1);
			pieceTexture.loadFromFile("images/platform.png");
			pieceSprite.setTexture(pieceTexture);
			if (random_num >332){
				random_num = 332;
			}
			
			pieceSprite.setPosition(random_num,random2);
			
			
			pos.x = random_num;
			pos.y = random2;
			
		}
		void setWindow(sf::RenderWindow* window) { this->window = window;}		
		void draw(){window->draw(pieceSprite);}		
		sf::Sprite getSprite(){	return pieceSprite;	}		
		void print_position(){
			cout << pieceSprite.getPosition().x <<endl;
			cout << pieceSprite.getPosition().y <<endl;
		}
		int get_position_y(){
			return pos.y;
		}
		/*void move(){
			if (pos.y>530){
				pos.y = rand()%30*(-1);
				pos.x = rand()%400;
				if(pos.x>352){
					pos.x=332;
				}
				
			}
			pieceSprite.setPosition(pos.x,pos.y);
		
			
		}*/
		void setPosition(int x, int y){
			pieceSprite.setPosition(x,y);
			pos.x = x;
			pos.y = y;
		}
		
};

class Doodle{
	sf::RenderWindow* window;
	sf::Texture pieceTexture;
	sf::Sprite pieceSprite;
	
	bool first_jump_bool=true;
	float dy2=0;
	int h=200;
	float dy=0,dx=0;
	vector<Platform*> platVec;
	int score=0;
	public:
		
		position pos;
		
		Doodle(){

			pieceTexture.loadFromFile("images/doodle.png");
			pieceSprite.setTexture(pieceTexture);
			
			pieceSprite.setPosition(200,490);
			
			pieceSprite.setOrigin(40.0,40.0);
			pos.x = pieceSprite.getPosition().x;
			pos.y = pieceSprite.getPosition().y;
			
		}
		
		void setWindow(sf::RenderWindow* window) { this->window = window;}	
		void setPlatform(vector<Platform*> platVec){this->platVec = platVec;}
	
		void draw(){window->draw(pieceSprite);}		
		sf::Sprite getSprite(){	return pieceSprite;	}		
		void get_position(){
			cout << pieceSprite.getPosition().x <<endl;
			cout << pieceSprite.getPosition().y <<endl;
		}
		void setPosition(int x, int y){
			pieceSprite.setPosition(x,y);
			pos.x = x;
			pos.y = y;
		}

		
		void move(){
			
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) pos.x+=3;
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) pos.x-=3;
			
			dy+=0.25;
			pos.y+=dy;
			dy2-=0.25;
			for(int i = 0;i<platVec.size();i++){
				if((pos.x+20>platVec[i]->getSprite().getPosition().x) && (pos.x-20<platVec[i]->getSprite().getPosition().x+68) && (pos.y+14<platVec[i]->getSprite().getPosition().y) && (pos.y+14>platVec[i]->getSprite().getPosition().y-20) && dy>=2){
					score+=10;
					dy = -10;
					cout<<"Score: "<<score<<endl;
					first_jump_bool=false;
					
					
					
					
					
				}
			}
			
			if(pos.y<200){
						
						for(int k = 0;k<platVec.size();k++){
							pos.y = 200;
						
							platVec[k]->setPosition(platVec[k]->getSprite().getPosition().x,platVec[k]->getSprite().getPosition().y-dy);
							if(platVec[k]->getSprite().getPosition().y>533){
								platVec[k]->setPosition(rand()%400,(rand()%200)*(-1));
							}
							
						}
						
						
					}
			
			
			
			if(pos.y>500&&first_jump_bool==true) dy=-10.0;
			
			if(pos.x<0) pos.x=0;
			if(pos.x>400) pos.x=400;
			
			if(pos.y<200){
				
				dy2=8;
				for(int i = 0;i<platVec.size();i++){
					platVec[i]->getSprite().setPosition(platVec[i]->getSprite().getPosition().x,platVec[i]->getSprite().getPosition().y+dy2);
				
				}
				dy2-=0.25;
			}
				
			pieceSprite.setPosition(pos.x,pos.y);
		}

		
};

int main() {
	Platform p13;Platform p14;Platform p15;Platform p16;Platform p17;Platform p18;Platform p19;Platform p20;
	Platform p21;	Platform p22;	Platform p23;	Platform p24;	Platform p25;	Platform p26;	Platform p28;	Platform p27;
	
	Doodle doodle;
	p19.setPosition(rand()%300,rand()%400);
	p20.setPosition(rand()%300,rand()%400);
	p21.setPosition(rand()%300,rand()%400);
	p22.setPosition(rand()%300,rand()%400);
	p23.setPosition(rand()%300,rand()%400);
	p24.setPosition(rand()%300,rand()%400);
	p25.setPosition(rand()%300,rand()%400);
	p26.setPosition(rand()%300,rand()%400);
	p27.setPosition(rand()%300,rand()%400);
	p28.setPosition(rand()%300,rand()%400);
	p18.setPosition(rand()%300,rand()%400);
	p17.setPosition(rand()%300,rand()%400);
	p16.setPosition(rand()%300,rand()%400);



	vector<Platform*> platformVec;

	platformVec.push_back(&p13);platformVec.push_back(&p14);platformVec.push_back(&p15);platformVec.push_back(&p16);
	platformVec.push_back(&p20);platformVec.push_back(&p19);platformVec.push_back(&p18);platformVec.push_back(&p17);
	platformVec.push_back(&p21);platformVec.push_back(&p22);platformVec.push_back(&p23);platformVec.push_back(&p24);
	platformVec.push_back(&p25);platformVec.push_back(&p26);platformVec.push_back(&p27);platformVec.push_back(&p28);

	doodle.setPlatform(platformVec);
	
	sf::RenderWindow window(sf::VideoMode(400, 533), "Doodle");
	window.setFramerateLimit(60);

	sf::Texture background;
	
	background.loadFromFile("images/background.png");	
	
	
	sf::Sprite s_bacground(background);	

	s_bacground.setPosition(0, 0);
	
	for(int i =0;i<platformVec.size();i++){
				platformVec[i]->setWindow(&window);
			}
	doodle.setWindow(&window);
	
	
	
	while (window.isOpen()) {
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))return 0;
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
			window.clear(sf::Color::Black);
		
		}
	
		doodle.move();
		
		window.draw(s_bacground);
	
		for(int i =0;i<platformVec.size();i++){
			platformVec[i]->draw();
		}
		
		if(doodle.pos.y>700) return 0;
		doodle.draw();

		window.display();	

	}

}


