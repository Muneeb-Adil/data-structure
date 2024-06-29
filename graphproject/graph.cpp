#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
// using STL library for dynamic array(vector),list and iterators(loop purpose)
#include<vector>
#include<list>
#include<iterator>
class route{
    private:
    string Destination_Department_name;
    float distance;
    public:
    route(string Destination_Department_name,float distance){
        this->Destination_Department_name=Destination_Department_name;
        this->distance=distance;
    };
    string get_Destination_DepartmentName(){
        return this->Destination_Department_name;
    };
    float get_Distance(){
        return this->distance;
    };
};

class Department{
    private:
    float Source_Department_latitude;
    float Source_Department_longitude;
    string Source_Department_name;
    public:
    list<route> department_list;
    Department(float Source_Department_latitude,float Source_Department_longitude,string Source_Department_name){
        this->Source_Department_latitude=Source_Department_latitude;
        this->Source_Department_longitude=Source_Department_longitude;
        this->Source_Department_name=Source_Department_name;
    };
    string get_Source_DepartmentName(){
        return this->Source_Department_name;
    };
    float get_latitude(){
        return this->Source_Department_latitude;
    }
    float get_longitude(){
        return this->Source_Department_longitude;
    }
    void get_department_list(){
        cout<<"[";
        for(auto it= department_list.begin(); it != department_list.end();it++){
            cout<<it->get_Destination_DepartmentName()<<"("<<it->get_Distance()<<")-->";
        }
        cout<<"]"<<endl;
    };
    void shortest_distance(Department source){

    }
};
class University_Map{
    private:
    vector<Department> all_connected_departments;
    public:
    void addDepartment(Department newDepartment){
        bool check = check_if_Department_exist(newDepartment.get_Source_DepartmentName());
        if(check == true){
            cout<<"Department with this name already exist"<<endl;
        }
        else{
            all_connected_departments.push_back(newDepartment);
            cout<<"New department added successfully"<<endl;
        }
    };
    bool check_if_Department_exist(string Departmentname){
        for(int i=0; i< all_connected_departments.size(); i++ ){
            if(all_connected_departments.at(i).get_Source_DepartmentName()== Departmentname){ //arr[0]=arr.at(0)
                return true;
            }
        }
        return false;
    };
    void addroute(Department route_from_d1,Department route_to_d2){
        bool check1=check_if_Department_exist(route_from_d1.get_Source_DepartmentName());
        bool check2=check_if_Department_exist(route_to_d2.get_Source_DepartmentName());
        if(check1 && check2 == true){
            bool check3=check_if_route_exist(route_from_d1,route_to_d2);
            if(check3 == true){
                cout<<"Route already exist between given departments"<<endl;
            }
            else{
                for(int i=0;i< all_connected_departments.size();i++){
                    float distance = calculate_distance(route_from_d1,route_to_d2);
                    if(all_connected_departments.at(i).get_Source_DepartmentName()== route_from_d1.get_Source_DepartmentName()){
                        route obj(route_to_d2.get_Source_DepartmentName(),distance);
                        all_connected_departments.at(i).department_list.push_back(obj);
                        
                    }
                    else if(all_connected_departments.at(i).get_Source_DepartmentName()== route_to_d2.get_Source_DepartmentName()){
                        route obj(route_from_d1.get_Source_DepartmentName(),distance);
                        all_connected_departments.at(i).department_list.push_back(obj);
                    }
                }
                cout<<"Route added successfully"<<endl;
            }
        }
        else{
            cout<<"No department exist with given name"<<endl;
        }
    };
    
    bool check_if_route_exist(Department route_from_d1,Department route_to_d2){
        list <route> r;
        r=route_from_d1.department_list;
        for(auto it = r.begin(); it!= r.end() ;it++ ){
            if(it->get_Destination_DepartmentName()== route_to_d2.get_Source_DepartmentName()){
                return true;
                break;
            }
        }
        return false;
    };

    float calculate_distance(Department d1,Department d2){
        float latitude_of_d1_in_radians=d1.get_latitude()*(180/M_PI);
        float longitude_of_d1_in_radians=d1.get_longitude()*(180/M_PI);
        float latitude_of_d2_in_radians=d2.get_latitude()*(180/M_PI);
        float longitude_of_d2_in_radians=d2.get_longitude()*(180/M_PI);
        float distance = 6378.8 * acos(sin(latitude_of_d1_in_radians)*sin(latitude_of_d2_in_radians)+cos(latitude_of_d1_in_radians)*cos(latitude_of_d2_in_radians)*cos(longitude_of_d2_in_radians-longitude_of_d1_in_radians));
        return distance;
    }

    void getallDepartments(){
        for(int i=0;i< all_connected_departments.size();i++){
            cout<<all_connected_departments.at(i).get_Source_DepartmentName()<<"-->";
            all_connected_departments.at(i).get_department_list();
            cout<<endl;
        }
    };

    
};

int main(){
    University_Map UOK;
    Department ubit(24.9455235,67.1154568,"UBIT");
    Department kubs(24.938392415701223, 67.1112736376929,"Karachi University Business School");
    Department pharmacy(24.941046614711976, 67.11761760072676,"DPA");
    UOK.addDepartment(ubit);
    UOK.addDepartment(kubs);
    UOK.addDepartment(pharmacy);
    UOK.addroute(ubit,kubs);
    UOK.addroute(ubit,pharmacy);
    kubs.shortest_distance(pharmacy);
    // UOK.getallDepartments();
    return 0;
}
//List your latitude coordinates before longitude coordinates.
// Check that the first number in your latitude coordinate is between -90 and 90.
// Check that the first number in your longitude coordinate is between -180 and 180.
//maskan gate 24.934652367559277, 67.10570192436155
//examination complex 24.936647374533543, 67.10965478885703
//kubs 24.938392415701223, 67.1112736376929
//iba boys hostel 24.93656515897235, 67.11058247851496
//faculty of law 24.937228509877933, 67.11405173650576
//k u b incubation center 24.936300632244095, 67.11468455046965
//silver jubliee 24.931600983836137, 67.11836795739153
// d o commerce 24.939897353685136, 67.1138048409847
//d o pharmacy 24.941046614711976, 67.11761760072676
// visual studies 24.937244142399127, 67.11686385490103
// gymnasium hall 24.937923838230613, 67.1179882264181
//institue os space and planetary astro physics 24.934486255283563, 67.11847201788193
//k u botanical garden 24.933729587993206, 67.12173052577785
//iba 24.942073509952127, 67.11429403601224
// mass comm 24.944690199723745, 67.11458216719718
// ubit 24.945760082390514, 67.11538252616954
// kaneez fatima society gate 1 24.94940950297773, 67.11241890910036
//faculty of pharmacy and pharmaceutical sciences 24.944164644006065, 67.1158116426752
//university chowrangi
//pakistan agricultural research council 24.942018691176784, 67.11867864300167
// d  o applied physics old 24.942947288374658, 67.12054439020504
// d o applied physics 24.94363995488558, 67.12040200786848
// d o statistics 24.944277759551586, 67.1201334095042
// acturial science 24.944859712950546, 67.12027746424369
//istitue of environmental studies 24.945279367800726, 67.1199881947593
//Dr. A.Q. Khan Institute of Biotechnology & Genetic Engineering 24.94672934149017, 67.11914930177004
//biotechnology 24.948638412699648, 67.11858128229346
// d o food science and technology 24.947636962443443, 67.11980802568787
// genetics 24.94668706195449, 67.12033428663358
// maths 24.94049751452172, 67.12144688047546
//psychology 24.938339089411446, 67.12083318716368
//criminology 24.93714182167978, 67.12116792897011
//education 24.938608895099375, 67.12200478244262
//urdu 24.93729358913718, 67.12057283138176
//d o engineering 24.93765348762784, 67.11872575003407
// faculty of art and social science 24.937721877214816, 67.11993403758636
//hitory 24.93767404493848, 67.12090112750407
//office of dean arts 24.937705933124754, 67.11996920449246
//philosophy 24.937100055929097, 67.12150775566933
//teacher education 24.939451798536155, 67.1219297580082
//geography 24.94040576960576, 67.1227561793501
//dean science 24.940820306192926, 67.12344193401901
//geology 24.94141553572021, 67.12216127181519
//applied chemistry 24.943102313108565, 67.1214492753136
//chemical engineering 24.945786088041547, 67.12163097227825
//petroleum 24.945291852642953, 67.12120017767855
//ku staff gate 24.93408689755164, 67.1293403899705
//special education 24.935214866163744, 67.13191503803736

